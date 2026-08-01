#include <stdio.h>
#include "math_alloc.h"
#include "vec.h"

int main(void) {
    BumpAllocator allo = bump_init(1000);

    // allocate an array of 5 vec3s THROUGH your allocator
    vec3 *verts = vec3_alloc_array(&allo, 5);

    // fill them
    verts[0] = (vec3){1, 2, 3};
    verts[1] = (vec3){4, 5, 6};
    // ... etc

    printf("buffer start: %p\n", (void *)allo.buffer);
    printf("verts:        %p\n", (void *)verts);
    printf("gap between verts[0] and verts[1]: %ld bytes (sizeof vec3 = %zu)\n",
        (char *)&verts[1] - (char *)&verts[0], sizeof(vec3));

    // USE your existing math functions on allocator-provided memory
    vec3 sum = vec3_add(verts[0], verts[1]);
    vec3_print(sum);   // should be (5, 7, 9)

    bump_free(&allo);
}