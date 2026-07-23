#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {

    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("short max:  %d\n", SHRT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("long min: %ld\n", LONG_MIN);
    printf("long max: %ld\n", LONG_MAX);
    
    unsigned int umax = ~0u;
    unsigned long ulong = ~0ul;
    int imax = ~0u >> 1;
    int min = -imax -1;
    long lmax= ~0ul >> 1;
    long lmin = -lmax - 1;
        /* signed char: N = CHAR_BIT bits */
    signed char scmax = (1 << (CHAR_BIT - 1)) - 1;   /* 2^7 - 1 = 127 */
    signed char scmin = -scmax - 1;                   /* -128 */
    printf("computed unsigned int max: %u\n", umax);
    printf("computed unsigned int max: %lu\n", ulong);
    printf("computed int max: %d\n", imax);
    printf("computed int min: %d\n", min);
    printf("computed long min: %ld\n", lmax);
    printf("comouted long min: %ld\n", lmin);
    printf("computer char max: %d\n", scmax);
    printf("computed char min: %d\n", scmin);
}
