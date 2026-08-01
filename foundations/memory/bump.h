#ifndef BUMP_H
#define BUMP_H

typedef struct {char *buffer; int total_size; int offset;} BumpAllocator;
void *bump_alloc(BumpAllocator *allocator, int size);
BumpAllocator bump_init(int total_size);
void bump_free(BumpAllocator *allocator);
#endif