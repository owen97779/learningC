#include <stdio.h>
#include <ctype.h>
#define MAX_DIGITS 10

/*
    012
0    _
1   |_|
2   |_|

*/

char digits[4][MAX_DIGITS * 4] = {0};
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

const char array[3][3] = {{' ', '_', ' '},
                          {'|', '_', '|'},
                          {'|', '_', '|'}};

void clear_digits_array(void);
void process_digit (int digit, int position);
void print_digits_array(void);

int main(void)
{
    char input;
    int position = 0;

    clear_digits_array();
    printf("Enter a number: ");
    while((input = getchar()) != '\n')
    {
        if(isdigit(input))
        {
            process_digit((input - '0'), position);
            position += 4;
        }
    }
    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < MAX_DIGITS * 4; j++)
        {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int j;
    for(j = 0; j < 7; j++)
    {
        if(segments[digit][j] && position < MAX_DIGITS * 4 - 2)
        {
            switch (j)
            {
            case 0:
                digits[0][position + 1] = array[0][1];
                break;
            case 1:
                digits[1][position + 2] = array[1][2];
                break;
            case 2:
                digits[2][position + 2] = array[2][2];
                break;
            case 3:
                digits[2][position + 1] = array[2][1];
                break;
            case 4:
                digits[2][position] = array[2][0];
                break;
            case 5:
                digits[1][position] = array[1][0];
                break;
            case 6:
                digits[1][position + 1] = array[1][1];
                break;
            default:
                break;
            }
        }
    }
    
}

void print_digits_array(void)
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < MAX_DIGITS * 4; j++)
        {
            putchar(digits[i][j]);
        }
        printf("\n");
    }
}
