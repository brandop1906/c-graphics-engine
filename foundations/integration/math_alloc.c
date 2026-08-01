#include "math_alloc.h"

vec3 *vec3_alloc_array(BumpAllocator *allo, size_t count) {
    vec3 *arr = (vec3 *)bump_alloc(allo, count * sizeof(vec3));
    return arr;
}