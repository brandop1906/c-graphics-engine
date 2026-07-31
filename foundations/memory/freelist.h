#ifndef FREELIST_H
#define FREELIST_H
#include <stdbool.h>
#include <stddef.h>

typedef struct Header { size_t size; bool is_free; struct Header *next; } Header;
typedef struct Allocator { char *buffer; size_t total_size; struct Header *head; } Allocator;
Allocator init(size_t total_size);
void *alloc(Allocator *allo, size_t size);
void free_chunk(Allocator *allo, void *ptr);
void destroy(Allocator *allo);
#endif