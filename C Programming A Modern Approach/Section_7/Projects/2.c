#include <stdio.h>

int main(void)
{
    int i, n;
    char j;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1, j = 1; i <= n; i++, j++)
    {
        printf("%10hd%10hd\n", i, i * i);
        if (j == 24)
        {
            printf("Press Enter to continue...");
            while(getchar() != '\n');
            j = 0;
        }
    }

    return 0;
}