#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void)
{
    char input, *p;
    char array[MAX_SIZE];
    int i = 0;
    
    printf("Enter words separated by a single whitespace: ");
    while((input = getchar()) != '\n' && i < MAX_SIZE)
    {
        array[i++] = input;
    }

    p = strtok(array, " ");
    printf("In reverse:");
    while(p != NULL)
    {
        p = strtok(NULL, " ");
    }

    p = &array[i];
    while(p >= array)
    {
        while(*p != '\0')
        {
            p--;
        }
        printf("%s ", (p + 1));
        p--;
    }
    

    return 0;
}