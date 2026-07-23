#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

Vector vec_create(void)
{
    Vector v;
    v.capacity = 4;
    v.count = 0;
    v.data = malloc(v.capacity * sizeof(int));
    return v;
}

int vec_push(Vector *v, int new_element)
{
    if (v->count == v->capacity)
    {
        int new_capacity = v->capacity * 2;
        int *temp = realloc(v->data, new_capacity * sizeof(int));
        if (temp == NULL)
        {
            return 0;
        }
        v->data = temp;
        v->capacity = new_capacity;
    }
    v->data[v->count] = new_element;
    v->count += 1;  
    return 1;
}

int vec_pop(Vector *v)
{
    if (v->count == 0)
    {
        printf("Error\n");
        return 0;
    }
    int element = v->data[v->count - 1];
    v->count--;
    return element;
}

void vec_free(Vector *v)
{
    free(v->data);
    v->data = NULL;
    v->count = 0;
    v->capacity = 0;
}

void vec_print(Vector *v)
{
    printf("count=%d capacity=%d : ", v->count, v->capacity);
    for (int i = 0; i < v->count; i++)
    {
        printf("%d ", v->data[i]);
    }
    printf("\n");
    
}