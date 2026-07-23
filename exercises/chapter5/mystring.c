#include <stdio.h>

int my_strlen(char s[])
{
    int counter = 0;
    while(s[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

char *my_strcpy(char dest[], char src[])
{
    int counter = 0;
    while((dest[counter] = src[counter]) != '\0')
        counter++;
    return dest;
}

void *my_memcpy(void *dest, void *src, int n)
{
    char *d = dest;
    char *s = src;
    int i;
    for (i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dest;
    

}

int main(void) 
{
    int source[4] = {1000000, 2000000, 3000000, 40000000};
    int dest[4];
    int i;
    
    my_memcpy(dest, source, 4 * sizeof(int));
    for (i = 0; i < 4; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");
    
    return 0;
}