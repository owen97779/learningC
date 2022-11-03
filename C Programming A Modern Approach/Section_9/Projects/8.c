#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char yes = 'Y', input;
    int wins = 0, losses = 0;
    
    srand(time(NULL));

    while(yes == 'Y')
    {
        
        if(play_game())
        {
            wins++;
        }
        else
        {
            losses++;
        }
        printf("Play again?: ");
        while((input = getchar()) != '\n')
        {
            yes = toupper(input);
        }
    }

    printf("Wins: %d\tLosses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    return rand() % 6 + rand() % 6 + 2;
}

bool play_game(void)
{
    int number = roll_dice();
    printf("You rolled: %d\n", number);
    if(number == 7 || number == 11)
    {
        printf("You win!\n");
        return true;
    }
    else if(number == 2 || number == 3 || number == 12)
    {
        printf("You lose!\n");
        return false;
    }
    else
    {
        printf("Your point is: %d\n", number);
        for(;;)
        {
            int subsequentNumber = roll_dice();
            printf("You rolled: %d\n", subsequentNumber);
            if(subsequentNumber == 7)
            {
                printf("You lose!\n");
                return false;
            }
            if(subsequentNumber == number)
            {
                printf("You win!\n");
                return true;
            }
        }
    }

}