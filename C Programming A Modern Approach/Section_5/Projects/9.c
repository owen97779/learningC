#include <stdio.h>

int main(void)
{
    int day1, month1, year1, day2, month2, year2;

    printf("Enter the first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month1, &day1, &year1);

    printf("Enter the second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month2, &day2, &year2);

    if (year2 > year1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month1, day1, year1, month2, day2, year2);
    }
    else if (year1 > year2)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month2, day2, year2, month1, day1, year1);
    }
    else if (month2 > month1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month1, day1, year1, month2, day2, year2);
    }
    else if (month1 > month2)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month2, day2, year2, month1, day1, year1);
    }
    else if (day2 > day1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month1, day1, year1, month2, day2, year2);
    }
    else if (day1 > day2)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d", month2, day2, year2, month1, day1, year1);
    }
    else
    {
        printf("%d/%d/%02d is equal to %d/%d/%02d", month2, day2, year2, month1, day1, year1);
    }
    
    return 0;
}