// Question 1: What state does the bump allocator need to remember between calls
// -buffer, size of memory, current offset
// Question 2: What are the inputs and outputs of the operation?
// -alloc takes a size (how many bytes we want) and returns a pointer void *alloc(size)
// Question 3: In plain english what has to happen step by step
// -someone wants N bytes, i look at where my free spot is, i give them a pointer to that spot. 
// -Then i move my free spots forward by N, so the next person gets fresh space. 
// Question 4: What can go wrong?
// - Can go past the allocated memory. Would need a check to make sure we cant go past the amount allocated
#include <stdio.h>
#include <stdlib.h>
#include "bump.h"

BumpAllocator bump_init(int total_size) {
    BumpAllocator allocator;
    allocator.buffer = malloc(total_size * sizeof(char));
    allocator.offset = 0;
    allocator.total_size = total_size;
    return allocator;
}

void *alloc(BumpAllocator *allocator, int size) {
    if (allocator->offset + size > allocator->total_size) {
        return NULL;
    }
    char *local = allocator->buffer + allocator->offset;
    allocator->offset += size;
    return local;
}

void bump_free(BumpAllocator *allocator) {
    free(allocator->buffer);
    allocator->buffer = NULL;
    allocator->offset = 0;
    allocator->total_size = 0;
}