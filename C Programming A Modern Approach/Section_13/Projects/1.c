#include <stdio.h>
#include <string.h>
#define maxLetters 20

char input[maxLetters + 1], smallest[maxLetters + 1], largest[maxLetters + 1];

void firstWord(void);
void anotherWord(void);

int main(void)
{
    firstWord();

    while(strlen(input) != 4)
    {
        anotherWord();
    }

    printf("Smallest Word: %s\nLargest Word: %s\n", smallest, largest);
    return 0;
}

void firstWord(void)
{
    printf("Enter word: ");
    scanf("%20s", input);
    strcpy(smallest, input);
    strcpy(largest, input);
}

void anotherWord(void)
{
    printf("Enter word: ");
    scanf("%20s", input);

    if(strcmp(input, smallest) < 0)
    {
        strcpy(smallest, input);
    }
    else if(strcmp(input, largest) > 0)
    {
        strcpy(largest, input);
    }
}