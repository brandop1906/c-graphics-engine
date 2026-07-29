#include <stdio.h>
#include <math.h>
#include "mat.h"
#include "vec.h"
# define M_PI		3.14159265358979323846

int main(void)
{   
    mat4 t = mat4_translate(5, 0, 0);
    mat4 rot = mat4_rotate_z(M_PI / 2.0);
    vec4 p = {1, 0, 0, 1};

    /* translate then rotate: move right, then spin */
    vec4 r1 = mat4_mul_vec4(mat4_mul(rot, t), p);
    /* rotate then translate: spin, then move right */
    vec4 r2 = mat4_mul_vec4(mat4_mul(t, rot), p);
    vec4_print(r1);
    vec4_print(r2);
    return 0;
}