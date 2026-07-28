// ===== FLAT ARRAY / COLUMN MAJOR ---  entry (row r, col c) is at m[c*4 + r] =====
#ifndef MAT_H
#define MAT_H
#include "vec.h"

typedef struct { float m[16]; } mat4;

mat4 mat4_identity(void);
vec4 mat4_mul_vec4(mat4 M, vec4 v);
void mat4_print(mat4 matrix);

#endif