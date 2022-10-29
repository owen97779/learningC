#include <stdio.h>

int main(void)
{
    int size, i, row, coll, rowOLD, collOLD;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    
    scanf("%d", &size);

    int array[size][size];

    for(row = 0; row < size; row++)
    {
        for(coll = 0; coll < size; coll++)
        {
            array[row][coll] = 0;
        }
    }

    row = 0;
    coll = size / 2;
    array[row][coll] = 1;

    for(i = 2; i <= size*size; i++)
    {
        rowOLD = row;
        collOLD = coll;
        if (rowOLD - 1 < 0)
        {
            row = size - 1;
        }
        else
        {
            row = rowOLD - 1;
        }
        if (collOLD + 1 >= size)
        {
            coll = 0;
        }
        else
        {
            coll = collOLD + 1;
        }
        if (array[row][coll] == 0)
        {
            array[row][coll] = i;
        }
        else
        {   
            if(rowOLD + 1 >= size)
            {
                array[row = 0][coll = collOLD] = i;
            }
            else
            {
                array[row = rowOLD + 1][coll = collOLD] = i;
            }
            
        }
    }

    for(row = 0; row <= size - 1; row++)
    {
        for(coll = 0; coll <= size - 1; coll++)
        {
            printf("%2d ", array[row][coll]);
        }
        printf("\n");
    }

    return 0;
}