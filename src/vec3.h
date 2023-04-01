#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double x, y, z;
} vec3_t;

inline double vec3_sqrmag(vec3_t v) {
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

inline double vec3_mag(vec3_t v) {
    return sqrt(vec3_sqrmag(v));
}

vec3_t vec3_scale(vec3_t v, double s) {
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

inline vec3_t vec3_neg(vec3_t v) {
    return vec3_scale(v, -1);
}

vec3_t vec3_add(vec3_t a, vec3_t b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

vec3_t vec3_sub(vec3_t a, vec3_t b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
    // return vec3_add(a, vec3_neg(b));
}

inline double vec3_dot(vec3_t a, vec3_t b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline vec3_t vec3_cross(vec3_t a, vec3_t b) {
    return (vec3_t){
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - b.x*a.y
    };
}

#endif