#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input, letter = 'A';
    int array[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10},
    score = 0;

    printf("Enter a word: ");

    while((input = getchar()) != '\n')
    {
        score += array[(int) toupper(input) - (int) letter];
    }

    printf("Scrabble value: %d", score);

    return 0;
}