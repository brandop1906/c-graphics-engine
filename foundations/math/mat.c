#include <stdio.h>
#include <math.h>
#include "mat.h"

mat4 mat4_identity(void)
{
    mat4 result;
    for (int j = 0; j < 16; j++)
    {
        result.m[j] = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        result.m[i * 4 + i] = 1;
    }
    return result;
}

vec4 mat4_mul_vec4(mat4 M, vec4 v)
{
    vec4 result;
    result.x = M.m[0] * v.x + M.m[4] * v.y + M.m[8] * v.z + M.m[12] * v.w;
    result.y = M.m[1] * v.x + M.m[5] * v.y + M.m[9] * v.z + M.m[13] * v.w;
    result.z = M.m[2] * v.x + M.m[6] * v.y + M.m[10] * v.z + M.m[14] * v.w;
    result.w = M.m[3] * v.x + M.m[7] * v.y + M.m[11] * v.z + M.m [15] * v.w;
    return result;
}

mat4 mat4_mul(mat4 A, mat4 B)
{
    mat4 result;
    for (int c = 0; c < 4; c++)
    {
        for (int r = 0; r < 4; r++)
        {
            float sum = A.m[r] * B.m[c * 4] + A.m[r + 4] * B.m[c * 4 + 1]
                + A.m[r + 8] * B.m[c * 4 + 2] + A.m[r + 12] * B.m[c * 4 + 3];
            result.m[c * 4 + r] = sum;
        }
    }
    return result;
}

mat4 mat4_scale(float sx, float sy, float sz)
{
    mat4 result = mat4_identity();
    result.m[0] = sx;
    result.m[5] = sy;
    result.m[10] = sz;
    result.m[15] = 1.0;
    return result;
}

mat4 mat4_translate(float tx, float ty, float tz)
{
    mat4 result = mat4_identity();
    result.m[12] = tx;
    result.m[13] = ty;
    result.m[14] = tz;
    return result;
}

mat4 mat4_rotate_z(float radians)
{
    mat4 result = mat4_identity();
    float c = cosf(radians);
    float s = sinf(radians);
    result.m[0] = c;
    result.m[1] = s;
    result.m[4] = -s;
    result.m[5] = c;
    return result;
}

mat4 mat4_rotate_y(float radians)
{
    mat4 result = mat4_identity();
    float c = cosf(radians);
    float s = sinf(radians);
    result.m[0] = c;
    result.m[2] = -s;
    result.m[8] = s;
    result.m[10] = c;
    return result;
}

mat4 mat4_rotate_x(float radians)
{
    mat4 result = mat4_identity();
    float c = cosf(radians);
    float s = sinf(radians);
    result.m[5] = c;
    result.m[6] = s;
    result.m[9] = -s;
    result.m[10] = c;
    return result;
}

void mat4_print(mat4 matrix)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("%.1f ", matrix.m[c*4 + r]);
        }
        printf("\n");
    }  
}