#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
    int size;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    
    scanf("%d", &size);
    char array[size][size];

    create_magic_square(size, array);
    print_magic_square(size, array);

    return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
    int i, row, coll, rowOLD, collOLD;

    for(row = 0; row < n; row++)
    {
        for(coll = 0; coll < n; coll++)
        {
            magic_square[row][coll] = 0;
        }
    }

    row = 0;
    coll = n / 2;
    magic_square[row][coll] = 1;

    for(i = 2; i <= n*n; i++)
    {
        rowOLD = row;
        collOLD = coll;
        if (rowOLD - 1 < 0)
        {
            row = n - 1;
        }
        else
        {
            row = rowOLD - 1;
        }
        if (collOLD + 1 >= n)
        {
            coll = 0;
        }
        else
        {
            coll = collOLD + 1;
        }
        if (magic_square[row][coll] == 0)
        {
            magic_square[row][coll] = i;
        }
        else
        {   
            if(rowOLD + 1 >= n)
            {
                magic_square[row = 0][coll = collOLD] = i;
            }
            else
            {
                magic_square[row = rowOLD + 1][coll = collOLD] = i;
            }
            
        }
    }
}

void print_magic_square(int n, char magic_square[n][n])
{
    for(int row = 0; row <= n - 1; row++)
    {
        for(int coll = 0; coll <= n - 1; coll++)
        {
            printf("%2d ", magic_square[row][coll]);
        }
        printf("\n");
    }
}