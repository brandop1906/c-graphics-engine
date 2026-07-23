#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int main()
{
    Vector vec = vec_create();
    for (int i = 0; i < 10; i++) 
    {
        vec_push(&vec, i * 10);
        vec_print(&vec); 
    }
    printf("popped: %d\n", vec_pop(&vec));  
    vec_print(&vec);                         
    printf("popped: %d\n", vec_pop(&vec));   
    vec_print(&vec);
    printf("popped: %d\n", vec_pop(&vec));   
    vec_print(&vec);                          
    printf("popped: %d\n", vec_pop(&vec)); 
    vec_free(&vec);
}
