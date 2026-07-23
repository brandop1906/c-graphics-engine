#include <stdio.h>
#include "vec.h"

int main(void)
{
    /* ---------- vec2 ---------- */
    vec2 a2 = {1, 2};
    vec2 b2 = {10, 20};
    vec2 e2 = {3, 4};
    vec2 xr = {1, 0};
    vec2 yr = {0, 1};

    printf("=== vec2 ===\n");

    printf("add      : ");  vec2_print(vec2_add(a2, b2));       printf("  expect 11.0 22.0\n");
    printf("subtract : ");  vec2_print(vec2_subtract(b2, a2));  printf("  expect 9.0 18.0\n");
    printf("scale    : ");  vec2_print(vec2_scale(a2, 3));      printf("  expect 3.0 6.0\n");

    printf("dot      : %.1f   expect 50.0\n", vec2_dot(a2, b2));      /* 1*10 + 2*20 */
    printf("dot perp : %.1f   expect 0.0\n",  vec2_dot(xr, yr));      /* perpendicular */
    printf("length   : %.1f   expect 5.0\n",  vec2_length(e2));       /* 3-4-5 */
    printf("length x : %.1f   expect 1.0\n",  vec2_length(xr));       /* unit */

    printf("normalize: ");  vec2_print(vec2_normalize(e2));     printf("  expect 0.6 0.8\n");
    printf("norm len : %.1f   expect 1.0\n", vec2_length(vec2_normalize(e2)));

    /* ---------- vec3 ---------- */
    vec3 a3 = {1, 2, 3};
    vec3 b3 = {4, 5, 6};
    vec3 e3 = {3, 4, 0};
    vec3 x3 = {1, 0, 0};
    vec3 y3 = {0, 1, 0};

    printf("\n=== vec3 ===\n");

    printf("add      : ");  vec3_print(vec3_add(a3, b3));       printf("  expect (5.0, 7.0, 9.0)\n");
    printf("subtract : ");  vec3_print(vec3_subtract(a3, b3));  printf("  expect (-3.0, -3.0, -3.0)\n");
    printf("scale    : ");  vec3_print(vec3_scale(a3, 2));      printf("  expect (2.0, 4.0, 6.0)\n");

    printf("dot      : %.1f   expect 32.0\n", vec3_dot(a3, b3));      /* 4+10+18 */
    printf("dot perp : %.1f   expect 0.0\n",  vec3_dot(x3, y3));
    printf("dot self : %.1f   expect 1.0\n",  vec3_dot(x3, x3));
    printf("length   : %.1f   expect 5.0\n",  vec3_length(e3));       /* 3-4-5 */

    printf("normalize: ");  vec3_print(vec3_normalize(e3));     printf("  expect (0.6, 0.8, 0.0)\n");
    printf("norm len : %.1f   expect 1.0\n", vec3_length(vec3_normalize(e3)));

    printf("cross xy : ");  vec3_print(vec3_cross(x3, y3));     printf("  expect (0.0, 0.0, 1.0)\n");
    printf("cross yx : ");  vec3_print(vec3_cross(y3, x3));     printf("  expect (0.0, 0.0, -1.0)\n");

    /* cross result must be perpendicular to both inputs */
    vec3 c = vec3_cross(a3, b3);
    printf("perp chk : %.1f %.1f   expect 0.0 0.0\n", vec3_dot(c, a3), vec3_dot(c, b3));

    /* ---------- edge cases ---------- */
    vec3 zero = {0, 0, 0};
    printf("\n=== edge ===\n");
    printf("zero len : %.1f   expect 0.0\n", vec3_length(zero));
    printf("zero norm: ");  vec3_print(vec3_normalize(zero));   printf("  expect (0.0, 0.0, 0.0) not crash/nan\n");

    return 0;
}