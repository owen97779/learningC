#include <stdio.h>

int main(void)
{
    int days, start, i, j=1;

    printf("Enter the number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    /* Sunday shall always remain the start of the week */
    scanf("%d", &start);

    while(j != start)
    {
        printf("\t");
        j++;
    }

    for(i = 1; i <= days; i++, j++)
    {
        if (j == 7)
        {
            printf("%3d\n", i);
            j = 1;
        }
        printf("%3d\t", i);
    }

    return 0;
}