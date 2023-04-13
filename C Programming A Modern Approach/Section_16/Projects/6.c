#include <stdio.h>

#define EARLIER -1
#define SAME 0
#define LATER 1

struct date{
        int month;
        int day;
        int year;
};

int compare_dates(struct date date1, struct date date2);
int total_days_in_year(struct date date);

int main(void)
{
    
    struct date date1, date2;

    int day1, month1, year1, day2, month2, year2;

    printf("Enter the first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &date1.month, &date1.day, &date1.year);

    printf("Enter the second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &date2.month, &date2.day, &date2.year);

    switch (compare_dates(date1, date2))
    {
    case LATER:
        printf("%d/%d/%02d comes before %d/%d/%02d\n", date2.month, date2.day, date2.year, date1.month, date1.day,
        date1.year);
        break;
    case EARLIER:
        printf("%d/%d/%02d comes before %d/%d/%02d\n", date1.month, date1.day, date1.year, date2.month, date2.day, 
        date2.year);
        break;
    default:
        printf("Same dates");
        break;
    }
    
    return 0;
}

int compare_dates(struct date date1, struct date date2)
{
    if (date1.year > date2.year)
    {
        return LATER;
    }
    else if (date2.year > date1.year)
    {
        return EARLIER;
    }

    /*Years are the same, compare days*/
    else
    {
        int d1_days = total_days_in_year(date1);
        int d2_days = total_days_in_year(date2);
        if (d1_days > d2_days)
        {
            return LATER;
        }
        else if ( d2_days > d1_days)
        {
            return EARLIER;
        }
        else
        {
            return SAME;
        }

    }
}

int total_days_in_year(struct date date)
{
    const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;

    for(int i = 0; i < date.month - 1; i++)
    {
        total_days += month_days[i];
    }

    return total_days + date.day;
}