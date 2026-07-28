#include <stdio.h>
#include "mat.h"
#include "vec.h"

int main(void)
{
    /* A scales by 2 in x, 3 in y */
    mat4 A = mat4_identity();
    A.m[0] = 2.0f;
    A.m[5] = 3.0f;

    /* B scales by 4 in x, 5 in y */
    mat4 B = mat4_identity();
    B.m[0] = 4.0f;
    B.m[5] = 5.0f;

    vec4 v = {1, 1, 1, 1};

    /* Method 1: compose, then apply */
    vec4 r1 = mat4_mul_vec4(mat4_mul(A, B), v);

    /* Method 2: apply B, then A */
    vec4 r2 = mat4_mul_vec4(A, mat4_mul_vec4(B, v));

    vec4_print(r1);
    vec4_print(r2);

    return 0;
}