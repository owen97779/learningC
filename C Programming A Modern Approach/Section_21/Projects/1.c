#include <stdio.h>
#include <stddef.h>

int main(void)
{
    struct s{
        char a;
        int b[2];
        float c;
    }test;

    printf("Size of a: %lu\n", sizeof(test.a));
    printf("Size of b: %lu\n", sizeof(test.b));
    printf("Size of c: %lu\n", sizeof(test.c));
    printf("Size of s: %lu\n", sizeof(test));

    printf("|%lu|%lu|%lu|\n", offsetof(struct s, a), offsetof(struct s, b), offsetof(struct s, c));

    /*
    Struct s is stored as 16 bytes on my machine, although the sum of all members is only 13 bytes.

    Output for offset on my machine is:
    |0|4|12|

    Implying that there is a three-byte hole between a and b members, and no hole between b and c.
    */
    return 0;
}