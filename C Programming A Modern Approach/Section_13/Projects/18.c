#include <stdio.h>

int main(void)
{
    char *p[] = {"January", "February", "March", "April",
                "May", "June", "July", "August",
                "September", "October", "November", "December"};
    
    int day, month, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month, &day, &year);

    printf("You entered the date %s %.2d, %.4d\n", p[month - 1], day, year);

    return 0;
}