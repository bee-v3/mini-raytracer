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
    const char* filename = "png_output.png";
    std::vector<char> imgbuffer(width * height * channels);
        for (int j = height - 1; j >= 0; --j) {
            for (int i = 0; i < width; i++) {
                color pixel(double(i) / (width - 1), (height - 1 - double(j)) / (height - 1), 0.25);
                imgbuffer[(j * height + i) * channels + 0] = pixel.x() * 255;
                imgbuffer[(j * height + i) * channels + 1] = pixel.y() * 255;
                imgbuffer[(j * height + i) * channels + 2] = pixel.z() * 255;
                
            }
        }
    stbi_write_png(filename, width, height, channels, imgbuffer.data(), 0);
    return 0;
}