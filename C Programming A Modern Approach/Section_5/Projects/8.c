#include <stdio.h>

int main(void)
{
    int dep1 = 8*60, dep2 = 9*60 + 43, dep3 = 11*60 + 19, dep4 = 12*60 + 47,
    dep5 = 14*60, dep6 = 15*60 + 45, dep7 = 19*60, dep8 = 21*60 + 45;

    printf("Enter a 24-hour time: ");
    int hours, mins;
    scanf("%d :%d",&hours,&mins);

    if (hours*60 + mins <= dep1 + (dep2 - dep1)/2)
    {
        printf("Closest depature time is 8.00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (hours*60 + mins <= dep2 + (dep3 - dep2)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else if (hours*60 + mins <= dep3 + (dep4 - dep3)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else if (hours*60 + mins <= dep4 + (dep5 - dep4)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else if (hours*60 + mins <= dep5 + (dep6 - dep5)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else if (hours*60 + mins <= dep6 + (dep7 - dep6)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else if (hours*60 + mins <= dep7 + (dep8 - dep7)/2)
    {
        printf("Closest depature time is 9.42 a.m., arriving at 11:52 a.m.\n");
    }
    else
    {
        printf("Closest depature time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }
    /* Doesen't work well for time between d8 and d1, to be fixed later*/

    return 0;
}