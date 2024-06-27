#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../external/stb/stb_image_write.h"

#include "Vadapter.h"
#include "verilated.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

bool readBMP(const char* filename, vector<uint8_t>& image, int& width, int& height, int& channels) {
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 3);
    if (!data) {
        cerr << "Error: Could not open the file." << endl;
        return false;
    }

    image.assign(data, data + width * height * 3);
    stbi_image_free(data);
    return true;
}

bool writeBMP(const char* filename, const vector<uint8_t>& image, int width, int height) {
    if (stbi_write_bmp(filename, width, height, 3, image.data()) == 0) {
        cerr << "Error: Could not create the output file." << endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vadapter *top = new Vadapter{contextp};

    vector<uint8_t> image;
    int width, height, channels;

    if (!readBMP("./res/lenna.bmp", image, width, height, channels)) {
        return -1;
    }

    vector<uint8_t> output_data;
    output_data.resize(image.size());

    top->rst = 1;
    top->clk = 0;
    top->eval();
    top->rst = 0;
    top->eval();


    // Write image data into the Verilog module
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * 3;
            uint8_t r = image[index + 0];
            uint8_t g = image[index + 1];
            uint8_t b = image[index + 2];
            top->data_in = (r << 16) | (g << 8) | b;
            std::cout << std::hex << top->data_in << std::endl;
            top->eval();
            top->clk = 1;
            top->eval();
            top->clk = 0;
            top->eval();

        }
    }


    // Switch to read mode
    top->rst = 1;
    top->mode = 1;
    top->eval();
    top->rst = 0;
    top->mode = 1;
    top->eval();

    int index = 0;
    // Read image data from the Verilog module
    // Read image data from the Verilog module
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x,index+=3) {
            top->eval();
            top->clk = 1;
            top->eval();
            output_data[index + 0] = (top->data_out >> 16) & 0xFF; // R
            output_data[index + 1] = (top->data_out >> 8) & 0xFF;  // G
            output_data[index + 2] = top->data_out & 0xFF;         // B
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
