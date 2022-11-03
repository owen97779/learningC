#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 26

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int counts1[26] = {0}, counts2[26] = {0};
    
    read_word(counts1);
    read_word(counts2);

    if(equal_array(counts1, counts2))
    {
        printf("They are anagrams.\n");
    }
    else
    {
        printf("They are not anagrams.\n");
    }

    return 0;
}

void read_word(int counts[26])
{
    char input;
    printf("Enter word: ");
    while((input = toupper(getchar())) != '\n')
    {
        if(isalpha(input))
        {
            counts[input - 'A'] += 1;
        }
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        if(counts1[i] != counts2[i])
        {
            return false;
        }
    }
    return true;
}