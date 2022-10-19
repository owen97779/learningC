#include <stdio.h>

int main(void)
{
    float average = 0;
    int length = 0;
    char input;

    printf("Enter a sentence: ");
    while((input = getchar()) != '\n')
    {
        switch (input)
        {
        case ' ':
            average = (average + (float) length) / 2;
            length = 0;
            break;
        
        default:
            length++;
            break;
        }
    }
    

    printf("Average word length: %.1f", average);

}