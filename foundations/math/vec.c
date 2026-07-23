#include <stdio.h>
#include <math.h>
#include "vec.h"

vec2 vec2_add(vec2 a, vec2 b)
{
    vec2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

vec2 vec2_subtract(vec2 a, vec2 b)
{
    vec2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

vec2 vec2_scale(vec2 a, float scalar)
{
    vec2 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    return result;
}

float vec2_dot(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

float vec2_length(vec2 v)
{
    return (sqrtf(vec2_dot(v, v)));
}

vec2 vec2_normalize(vec2 v)
{
    float len = vec2_length(v);
    if (len == 0)
        return v;
    return vec2_scale(v, 1.0f / len);
}

void vec2_print(vec2 v)
{
    printf("%.1f %.1f\n", v.x, v.y);
}

vec3 vec3_add(vec3 a, vec3 b) 
{
    vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vec3 vec3_subtract(vec3 a, vec3 b)  
{
    vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

vec3 vec3_scale(vec3 a, float scalar) 
{
    vec3 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}

float vec3_dot(vec3 a, vec3 b) 
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float vec3_length(vec3 v)
{
    return sqrtf(vec3_dot(v, v));
}

vec3 vec3_normalize(vec3 v)
{
    float len = vec3_length(v);
    if (len == 0.0f)
        return v;
    return vec3_scale(v, 1.0f / len);
}

vec3 vec3_cross(vec3 a, vec3 b)
{
    vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

void vec3_print(vec3 v)
{
    printf("(%.1f, %.1f, %.1f)\n", v.x, v.y, v.z);
}