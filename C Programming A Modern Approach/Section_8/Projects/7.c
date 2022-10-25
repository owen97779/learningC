#include <stdio.h>

int main(void)
{
    int array[5][5] = {0},
    i, row_total, col_total;

   
    for(i = 0; i <= 4; i++)
    {
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4]);
    }

    printf("Row totals: ");
    for(row_total = 0, i = 0; i <= 4; i++, row_total = 0)
    {
        row_total = array[i][0] + array[i][1] + array[i][2] + array[i][3] + array[i][4];
        printf("%d ", row_total);
    }

    printf("\nColumn totals: ");
    for(col_total = 0, i = 0; i <= 4; i++, col_total = 0)
    {
        col_total = array[0][i] + array[1][i] + array[2][i] + array[3][i] + array[4][i];
        printf("%d ", col_total);
    }

    return 0;
}