#include "Vadapter.h"
#include "verilated.h"
#include "bmp.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

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
