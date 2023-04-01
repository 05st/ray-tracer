#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    // dir is a normalized (unit) vector
    vec3_t origin, dir;
} ray_t;

vec3_t ray_at(ray_t r, double t);

#endif