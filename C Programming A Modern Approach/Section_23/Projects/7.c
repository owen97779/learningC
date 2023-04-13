#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void)
{
    char input;
    int sentences = 0;

    while((input = getchar()) != EOF)
    {
        if(strchr(".?!", input) != NULL)
        {
            sentences++;
        }
    }

    printf("There are %d sentences.\n", sentences);
    return 0;
}