#ifndef MATH_ALLOC_H
#define MATH_ALLOC_H
#include <stddef.h>
#include "vec.h"
#include "bump.h"

vec3 *vec3_alloc_array(BumpAllocator *allocator, size_t count);
#endif
