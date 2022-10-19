#include <stdio.h>

int main(void)
{
    printf("Size of integer: %d bytes\nSize of short: %d bytes\nSize of long: %d bytes\n", 
    sizeof(int), sizeof(short), sizeof(long));
    printf("Size of float: %d bytes\nSize of double: %d bytes\nSize of long double: %d bytes",
    sizeof(float), sizeof(double), sizeof(long double));

    return 0;
}