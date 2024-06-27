#include "Vadapter.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

// BMP Header structures
#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
};

struct BMPInfoHeader {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};
#pragma pack(pop)

bool readBMP(const char* filename, vector<uint8_t>& image, int& width, int& height) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        return false;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (fileHeader.fileType != 0x4D42) {
        cerr << "Error: Not a BMP file." << endl;
        return false;
    }

    width = infoHeader.width;
    height = abs(infoHeader.height);
    int rowPadded = (width * 3 + 3) & (~3);
    image.resize(rowPadded * height);

    file.seekg(fileHeader.offsetData, ios::beg);
    file.read(reinterpret_cast<char*>(image.data()), image.size());

    file.close();
    return true;
}

bool writeBMP(const char* filename, const vector<uint8_t>& image, int width, int height) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "[ERROR]: Could not open the file for writing." << endl;
        return false;
    }

    BMPFileHeader fileHeader = {};
    BMPInfoHeader infoHeader = {};

    fileHeader.fileType = 0x4D42; // 'BM'
    fileHeader.fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + image.size();
    fileHeader.offsetData = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = -height; // Negative to indicate top-down bitmap
    infoHeader.planes = 1;
    infoHeader.bitCount = 24;
    infoHeader.sizeImage = image.size();

    file.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));
    file.write(reinterpret_cast<const char*>(image.data()), image.size());

    file.close();
    return true;
}

int main(int argc, char **argv) {
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vadapter *top = new Vadapter{contextp};

    vector<uint8_t> image;
    int width, height;

    if (!readBMP("./res/lenna.bmp", image, width, height)) {
        return -1;
    }

    vector<uint8_t> output_data;
    output_data.resize(image.size());

    top->rst = 1;
    top->clk = 0;
    top->start_in = 0;
    top->eval();
    top->rst = 0;
    top->eval();

    // Write image data into the Verilog module
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int rowPadded = (width * 3 + 3) & (~3);
            int index = (height - y - 1) * rowPadded + x * 3;
            uint8_t r = image[index + 2];
            uint8_t g = image[index + 1];
            uint8_t b = image[index + 0];
            top->data_in = (r << 16) | (g << 8) | b;
            top->start_in = 1;
            top->eval();
            top->clk = 1;
            top->eval();
            top->clk = 0;
            top->eval();
        }
    }

    // Switch to read mode
    top->rst = 1;
    top->eval();
    top->rst = 0;
    top->eval();
    top->mode = 1;
    top->eval();

    // Read image data from the Verilog module
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            top->eval();
            top->clk = 1;
            top->eval();
            int rowPadded = (width * 3 + 3) & (~3);
            int index = (height - y - 1) * rowPadded + x * 3;
            output_data[index + 2] = (top->data_out >> 16) & 0xFF; // R
            output_data[index + 1] = (top->data_out >> 8) & 0xFF;  // G
            output_data[index + 0] = top->data_out & 0xFF;         // B
            top->clk = 0;
            top->eval();
        }
    }

    // Save output data to BMP file
    if (!writeBMP("output_lenna.bmp", output_data, width, height)) {
        return -1;
    }

    delete top;
    delete contextp;
    return 0;
}
