#include <stdio.h>

int main(void)
{
    int one, two, three, 
    four, five, six, seven, 
    eight, nine, ten, eleven, 
    twelve, thirteen, fourteen, 
    fifteen, sixteen;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
    &one, &two, &three, &four, &five, &six, &seven, &eight, &nine,
    &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);

    printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n",
    one, two, three, four, five, six, seven, eight, nine, ten, eleven, 
    twelve, thirteen, fourteen, fifteen, sixteen);

    int rowSum1 = one + two + three + four;
    int rowSum2 = five + six + seven + eight;
    int rowSum3 =  nine + ten + eleven + twelve;
    int rowSum4 = thirteen + fourteen + fifteen + sixteen;

    int colSum1 = one + five + nine + thirteen;
    int colSum2 = two + six + ten + fourteen;
    int colSum3 = three + seven + eleven + fifteen;
    int colSum4 = four + eight + twelve + sixteen;

    int diag1 = one + six + eleven + sixteen;
    int diag2 = four + seven + ten + thirteen;

    printf("Row Sums: %d %d %d %d\n", rowSum1, rowSum2, rowSum3, rowSum4);
    printf("Column Sums: %d %d %d %d\n", colSum1, colSum2, colSum3, colSum4);
    printf("Diagonal Sums: %d %d\n", diag1, diag2);

    return 0;
}