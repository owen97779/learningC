#include <stdio.h>

int main(void)
{
    int day1, month1, year1, day2, month2, year2;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month1, &day1, &year1);

    while(1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%d", &month2, &day2, &year2);
        
        if(year2 == 0 & month2 == 0 & day2 == 0)
        {
            break;
        }
        else if (year1 > year2)
        {
            day1 = day2, month1 = month2, year1 = year2;
        }
        else if (year2 > year1)
        {
            continue;
        }
        else if (month1 > month2)
        {
            day1 = day2, month1 = month2, year1 = year2;
        }
        else if (month2 > month1)
        {
            continue;
        }
        else if (day1 > day2)
        {
            day1 = day2, month1 = month2, year1 = year2;
        }
        else if (day2 > day1)
        {
            continue;
        }
        else
        {
            continue;
        }
    }

    printf("%d/%d/%02d is the earliest date", month1, day1, year1);

    return 0;
}