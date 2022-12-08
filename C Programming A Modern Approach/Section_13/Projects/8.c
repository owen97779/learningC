#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 50

int compute_scrabble_value(const char *word);

int main(void)
{
    char word[MAXSIZE];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int score = 0;
    int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 
                1, 1, 3, 10, 1, 8, 1, 1, 4, 4, 8, 4, 10};
    
    while(*word != '\0')
    {
        score += scores[toupper(*word++) - 'A'];
    }

    return score;
}