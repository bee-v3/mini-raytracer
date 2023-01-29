#define STBI_ONLY_PNG
#include <vector>
#include <iostream>
#include <algorithm>
#include "vec3.h"
#include "ray.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main()
{
    const auto aspect_ratio = 16.0 / 9.0;
    const int img_width = 600;
    const int img_height = static_cast<int>(img_width / aspect_ratio);
    const int channels = 3;

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
    const char* filename = "png_output.png";

    std::vector<char> imgbuffer(img_width * img_height * channels);
    
    // Counter for the image buffer
    int index = 0;
    // Loop through each pixel in the image
    for (int j = img_height - 1; j >= 0; --j) {
        
        for (int i = 0; i < img_width; ++i) {
            auto u = double(i) / (img_width - 1);
            auto v = double(j) / (img_height - 1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel = ray_color(r);

            imgbuffer[index++] = pixel.x() * 255;
            imgbuffer[index++] = pixel.y() * 255;
            imgbuffer[index++] = pixel.z() * 255;
            
        }
    }
    stbi_write_png(filename, img_width, img_height, channels, imgbuffer.data(), 0);

    std::cerr << std::endl << "Done" << std::endl;
    return 0;
}