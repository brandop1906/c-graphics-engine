// ===== FLAT ARRAY / COLUMN MAJOR ---  entry (row r, col c) is at m[c*4 + r] =====
#ifndef MAT_H
#define MAT_H
#include "vec.h"

typedef struct { float m[16]; } mat4;

mat4 mat4_identity(void);
vec4 mat4_mul_vec4(mat4 M, vec4 v);
mat4 mat4_mul(mat4 A, mat4 B);
mat4 mat4_scale(float sx, float sy, float sz);
mat4 mat4_translate(float tx, float ty, float tz);
mat4 mat4_rotate_z(float radians);
mat4 mat4_rotate_y(float radians);
mat4 mat4_rotate_x(float radians);
void mat4_print(mat4 matrix);

#endif