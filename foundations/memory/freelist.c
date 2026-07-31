#include <stdio.h>
#include <stdlib.h>
#include "freelist.h"

#define MIN_LEFTOVER 1

Allocator init(size_t total_size) {
    Allocator allo;
    allo.buffer = malloc(total_size);
    allo.total_size = total_size;
    Header *first = (Header *)allo.buffer;
    first->is_free = true;
    first->size = total_size - sizeof(Header);
    first->next = NULL;
    allo.head = first;
    return allo;
}

void *alloc(Allocator *allo, size_t size) {
    Header *current = allo->head;
    Header *prev = NULL;
    while (current != NULL) {
        if (current->is_free && current->size >= size) {
            break;
        }
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    }

    if (current->size >= size + sizeof(Header) + MIN_LEFTOVER) {
        char *leftover_addr = (char *)current + sizeof(Header) + size;
        Header *leftover = (Header *)leftover_addr;
        leftover->size = current->size - size - sizeof(Header);
        leftover->is_free = true;
        leftover->next = current->next;
        current->size = size;
        current->is_free = false;

        if (prev == NULL) {
            allo->head = leftover;
        } else {
            prev->next = leftover;
        }
    } else {
        current->is_free = false;
        if (prev == NULL) {
            allo->head = current->next;
        } else {
            prev->next = current->next;
        }
    }
    return (char *)current + sizeof(Header);
}

void free_chunk(Allocator *allo, void *ptr) {
    Header *header = (Header *)((char *)ptr - sizeof(Header));
    header->is_free = true;
    header->next = allo->head;
    allo->head = header;
}

void destroy(Allocator *allo) {
    free(allo->buffer);
    allo->buffer = NULL;
}