#include <stdio.h>
#include <stdbool.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

#include "vec3.h"
#include "ray.h"

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

bool hit_sphere(vec3_t center, double radius, ray_t ray) {
    vec3_t oc = vec3_sub(ray.origin, center);
    double a = vec3_sqrmag(ray.dir);
    double b = 2.0 * vec3_dot(oc, ray.dir);
    double c = vec3_sqrmag(oc) - radius*radius;
    return (b*b - 4*a*c) > 0;
}

int main() {
    double aspect_ratio = (double)IMG_WIDTH / (double)IMG_HEIGHT;
    double viewport_height = 2.0, viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    vec3_t camera_pos = {0, 0, 0};
    vec3_t horizontal = {viewport_width, 0, 0}, vertical = {0, viewport_height, 0};
    vec3_t corner = vec3_sub(vec3_sub(vec3_add(camera_pos, vec3_mul(vertical, 0.5)), vec3_mul(horizontal, 0.5)), (vec3_t){0, 0, focal_length});
    
    vec3_t sphere_center = {0, 0, -1};
    double sphere_radius = 0.5;

    for (int j = 0; j < IMG_HEIGHT; j++) {
        for (int i = 0; i < IMG_WIDTH; i++) {
            double u = (double)i / (double)(IMG_WIDTH - 1), v = (double)j / (IMG_HEIGHT - 1);
            vec3_t ray_dir = vec3_unit(vec3_sub(vec3_sub(vec3_add(corner, vec3_mul(horizontal, u)), vec3_mul(vertical, v)), camera_pos));
            ray_t ray = {camera_pos, ray_dir};

            if (hit_sphere(sphere_center, sphere_radius, ray))
                write_color((vec3_t){0.1, 0.2, u});
            else
                write_color((vec3_t){1.0, 1.0, 1.0});
        }
    }

    write_img();
    return 0;
}