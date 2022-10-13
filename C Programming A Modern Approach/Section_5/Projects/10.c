#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);
    
    if (grade > 100 || grade < 0)
    {
        grade = -11;
    }

    switch (grade/10)
    {
    case 10:
        printf("Letter grade: A");
        break;
    case 9:
        printf("Letter grade: A");
        break;
    case 8:
        printf("Letter grade: B");
        break;
    case 7:
        printf("Letter grade: C");
        break;
    case 6:
        printf("Letter grade: D");
        break;
    case 5:
        printf("Letter grade: E");
        break;
    case 4:
        printf("Letter grade: E");
        break;
    case 3:
        printf("Letter grade: E");
        break;
    case 2:
        printf("Letter grade: E");
        break;
    case 1:
        printf("Letter grade: E");
        break;
    case 0:
        printf("Letter grade: E");
        break;    
    default:
        printf("Error, invalid grade");
        break;
    }

    return 0;
}