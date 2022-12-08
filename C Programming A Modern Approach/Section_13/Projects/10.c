#include <stdio.h>
#define MAX 50

void reverse_name(char *name);

int main(void)
{
    char name[MAX];

    printf("Enter a first and last name: ");
    fgets(name, MAX, stdin);
    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name;

    while(*p++ == ' ');
    
    char *q = p;
    
    while(*q++ != ' ');
    while(*q == ' ' && *q++ == ' ');

    while(*q != '\n')
    {
        putchar(*q++);
    }
    printf(", %c.\n", *--p);
}