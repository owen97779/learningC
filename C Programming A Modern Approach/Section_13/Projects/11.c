#include <stdio.h>
#include <ctype.h>

#define MAX 50

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[MAX];

    printf("Enter a sentence: ");
    fgets(sentence, MAX - 1, stdin);

    printf("The average word length is: %.1f\n", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    double length = 0, words = 0;
    double average = 0;

    while(*sentence)
    {
        while(*sentence && !isspace(*sentence))
        {
            length++;
            sentence++;
        }
        

        while(*sentence && isspace(*sentence))
        {
            sentence++;
        }

        words++;
    }

    return average = length / words;
}