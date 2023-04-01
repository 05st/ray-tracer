#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double x, y, z;
} vec3_t;

double vec3_sqrmag(vec3_t v);
double vec3_mag(vec3_t v);
vec3_t vec3_mul(vec3_t v, double s);
vec3_t vec3_neg(vec3_t v);
vec3_t vec3_add(vec3_t a, vec3_t b);
vec3_t vec3_sub(vec3_t a, vec3_t b);
double vec3_dot(vec3_t a, vec3_t b);
vec3_t vec3_cross(vec3_t a, vec3_t b);
vec3_t vec3_div(vec3_t v, double s);
vec3_t vec3_unit(vec3_t v);

#endif