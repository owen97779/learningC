#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/* 
Moves:

    0
1       3
    2

*/
int main(void)
{
    char array[10][10] = {0};
    char letter = 'A';
    int move, i = 0, j = 0;
    bool move0, move1, move2, move3;

    srand((unsigned) time(NULL));
    array[i][j] = letter++;

    while((move0 || move1 || move2 || move3) && letter <= 'Z')
    {
        move0 = move1 = move2 = move3 = false;
        
        if (j + 1 <= 9 && array[i][j + 1] == 0)
            move3 = true;
        if (j - 1 >= 0 && array[i][j - 1] == 0)
            move1 = true;
        if (i + 1 <= 9 && array[i + 1][j] == 0)
            move2 = true;
        if (i - 1 >= 0 && array[i - 1][j] == 0)
            move0 = true;

        if (move0 == false && move1 == false && move2 == false && move3 == false)
            break;

        move = rand() % 4;

        switch (move)
        {
        case 0:
            if(((i - 1) >= 0) && array[i - 1][j] == 0 && move0)
            {
                array[--i][j] = letter++;
            }
            break;
        case 1:
            if(((j - 1) >= 0) && array[i][j - 1] == 0 && move1)
            {
                array[i][--j] = letter++;
            }
            break;
        case 2:
            if(((i + 1) <= 9) && array[i + 1][j] == 0 && move2)
            {
                array[++i][j] = letter++;
            }
            break;
        case 3:
            if(((j + 1) <= 9) && array[i][j + 1] == 0 && move3)
            {
                array[i][++j] = letter++;
            }
            break;
        
        default:
            break;
        }
    }

    for (i = 0; i < 10; i++) 
    {
       for (j = 0; j < 10; j++) 
       {
           if(array[i][j] == 0)
           {
               array[i][j] = '.';
           } 
           printf("%c ", array[i][j]);
       }
       printf("\n");
    }

    return 0;
}