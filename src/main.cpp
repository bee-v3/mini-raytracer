#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <vector>
#include "vec3.h"

int main()
{/*
    int width, height, channels;
    unsigned char* data = stbi_load("image.png", &width, &height, &channels,4);
    stbi_write_png("image2.png", width, height, channels, data, width * channels);
    stbi_image_free(data);
*/
    int width = 512, height = 512, channels = 3;
    std::vector<char> imgbuffer(width * height * channels);
        for (int j = height - 1; j >= 0; --j) {
            for (int i = 0; i < width; i++) {
                imgbuffer[(j * height + i) * channels + 0] = (double(i) / (width - 1) * 255.999);
                imgbuffer[(j * height + i) * channels + 1] = (double(j) / (height -1) * 255.999);
                imgbuffer[(j * height + i) * channels + 2] = 0;
            }
        }
    stbi_write_png("rainbow.png", width, height, channels, imgbuffer.data(), 0);
    return 0;
}