#ifndef DYNARRAY_H
#define DYNARRAY_H

typedef struct {int *data; int capacity; int count;} Vector;

Vector vec_create(void);
int vec_push(Vector *v, int new_element);
int vec_pop(Vector *v);
void vec_free(Vector *v);
void vec_print(Vector *v);

#endif
