#include <stdio.h>  

int main(void)  
{  
    float r = 10.0;

    r = r * r * r;
    float volume;
    volume = (4.0f / 3.0f) * ( 3.14 * r);
    printf("Volume of Sphere: %.2f\n", volume);
}