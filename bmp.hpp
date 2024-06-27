#ifndef BMP_HPP
#define BMP_HPP

#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>

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
        cerr << "Error: Could not open the file for writing." << endl;
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

#endif // BMP_HPP
