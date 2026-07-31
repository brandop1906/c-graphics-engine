#include <stdio.h>
#include "freelist.h"

int main(void) {
    Allocator allo = init(1000);
    printf("after init: buffer = %p\n", (void *)allo.buffer);
    // write ints through both, read back — confirm usable and separate
    void *p1 = alloc(&allo, 100);
    printf("after alloc1: buffer = %p\n", (void*)allo.buffer);
    printf("p1: %p\n", p1);
    free_chunk(&allo, p1);
    printf("after free:   buffer = %p\n", (void*)allo.buffer);
    void *p2 = alloc(&allo, 100);
    printf("after alloc2: buffer = %p\n", (void*)allo.buffer);
    printf("p2: %p\n", p2);

    if (p1 == p2) printf("REUSE WORKS — freed memory handed back out\n");
    destroy(&allo);
    return 0;
}