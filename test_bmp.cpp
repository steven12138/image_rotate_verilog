#include "bmp.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_bmp>" << std::endl;
        return 1;
    }

    const char* input_path = argv[1];
    const char* output_path = "./output.bmp";

    vector<uint8_t> image;
    int width, height;

    if (!readBMP(input_path, image, width, height)) {
        return -1;
    }

    if (!writeBMP(output_path, image, width, height)) {
        return -1;
    }

    std::cout << "BMP file read and saved successfully to " << output_path << std::endl;
    return 0;
}
