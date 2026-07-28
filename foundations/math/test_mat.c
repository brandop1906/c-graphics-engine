#include <stdio.h>
#include "mat.h"
#include "vec.h"

int main(void)
{

    vec4 v = {5, 10, 15, 1};
    vec4 r = mat4_mul_vec4(mat4_identity(), v);
    vec4_print(r);

    return 0;
}