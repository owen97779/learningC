#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[20], word2[20];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    if(are_anagrams(word1, word2))
    {
        printf("The words are anagrams.\n");
    }
    else
    {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    for(;*word2 != '\0'; word2++);
    word2--;

    while(*word1)
    {
        if(toupper(*word1) == toupper(*word2))
        {
            word1++;
            word2--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
