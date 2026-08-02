#include <stdio.h>
#include <math.h>
#include "vec.h"
#include "mat.h"

#define M_PI 3.14159265358979323846

vec4 points[3] = {
    {0, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1}
};

int main(void) {
    mat4 transform = mat4_rotate_z(M_PI / 2.0f); // rotate 90 degrees around Z axis
    for (int i = 0; i < 3; i++) {
        vec4 result = mat4_mul_vec4(transform, points[i]);
        printf("Point %d: (%.1f, %.1f, %.1f) -> (%.1f, %.1f, %.1f)\n",
            i, points[i].x, points[i].y, points[i].z,
                result.x, result.y, result.z);
    }
    return 0;
}