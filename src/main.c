#include "stdio.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

#include "vec3.h"

#define IMG_WIDTH 1280
#define IMG_HEIGHT 720
#define IMG_CHANNELS 3
char img_data[IMG_WIDTH * IMG_HEIGHT * IMG_CHANNELS];

void write_color(vec3_t rgb) {
    static int idx = 0;
    img_data[idx++] = 255 * rgb.x;
    img_data[idx++] = 255 * rgb.y;
    img_data[idx++] = 255 * rgb.z;
}

void write_img() {
    stbi_write_png("out.png", IMG_WIDTH, IMG_HEIGHT, IMG_CHANNELS, img_data, IMG_WIDTH * IMG_CHANNELS);
    stbi_write_jpg("out.jpg", IMG_WIDTH, IMG_HEIGHT, IMG_CHANNELS, img_data, IMG_WIDTH * IMG_CHANNELS);
}

int main() {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            vec3_t color = {0.1f, 0.2f, (float)j / IMG_WIDTH};
            write_color(color);
        }
    }

    write_img();
    return 0;
}