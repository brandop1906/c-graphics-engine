#include <stdio.h>
#include "bump.h"

int main(void) {
    BumpAllocator allocator = bump_init(1000);
    void *p1 = alloc(&allocator, 40);
    void *p2 = alloc(&allocator, 100);
    int *a = p1;
    int *b = p2;
    *a = 111;
    *b = 222;
    printf("%d\n", *a);
    printf("%d\n", *b);
    void *p3 = alloc(&allocator, 2100);
    if (p3 == NULL) printf("guard fired correctly\n");
    bump_free(&allocator);
}