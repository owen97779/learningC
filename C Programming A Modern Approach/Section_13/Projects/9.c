#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 50

int compute_vowel_count(const char *sentence);

int main(void)
{
    char input;
    char sentence[MAXSIZE], *p = sentence;

    printf("Enter a sentence: ");
    while((input = getchar()) != '\n')
    {
        *p++ = input;
    }   
    
    printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;

    while(*sentence != '\0')
    {
        switch (toupper(*sentence++))
        {
        case 'A': case 'E': case 'I': case 'O': case 'U':
            vowels++;
            break;
        default:
            break;
        }
    }

    return vowels;
}