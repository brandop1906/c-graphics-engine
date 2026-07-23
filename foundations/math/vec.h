#ifndef VEC_H
#define VEC_H

typedef struct { float x, y; } vec2;
typedef struct { float x, y, z; } vec3;
typedef struct { float x, y, z, w; } vec4;

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_subtract(vec2 a, vec2 b);
vec2 vec2_scale(vec2 a, float scalar);
float vec2_dot(vec2 a, vec2 b);
float vec2_length(vec2 v);
vec2 vec2_normalize(vec2 v);
void vec2_print(vec2 v);

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_subtract(vec3 a, vec3 b);
vec3 vec3_scale(vec3 a, float scalar);
float vec3_dot(vec3 a, vec3 b);
float vec3_length(vec3 v);
vec3 vec3_normalize(vec3 v);
vec3 vec3_cross(vec3 a, vec3 b);
void vec3_print(vec3 v);

vec4 vec4_add(vec4 a, vec4 b);
vec4 vec4_subtract(vec4 a, vec4 b);
vec4 vec4_scale(vec4 a, float scalar);
float vec4_dot(vec4 a, vec4 b);
float vec4_length(vec4 v);
vec4 vec4_normalize(vec4 v);
vec4 vec4_cross(vec4 a, vec4 b);
void vec4_print(vec4 v);

#endif