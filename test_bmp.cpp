#define STB_IMAGE_IMPLEMENTATION
#include "external/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb/stb_image_write.h"

#include <iostream>

int main() {
    int width, height, channels;

    // 使用 stb_image 读取 BMP 文件
    unsigned char* data = stbi_load("./res/lenna.bmp", &width, &height, &channels, 3);
    if (!data) {
        std::cerr << "无法读取文件！" << std::endl;
        return 1;
    }

    std::cout << "图像宽度: " << width << std::endl;
    std::cout << "图像高度: " << height << std::endl;
    std::cout << "每个像素的位数: " << channels * 8 << std::endl;

    // 使用 stb_image_write 写入 BMP 文件
    if (stbi_write_bmp("output.bmp", width, height, 3, data) == 0) {
        std::cerr << "无法创建输出文件！" << std::endl;
        stbi_image_free(data);
        return 1;
    }

    stbi_image_free(data);
    std::cout << "BMP 文件已成功保存到 output.bmp" << std::endl;

    return 0;
}
