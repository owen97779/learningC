#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int dep1 = 8*60, dep2 = 9*60 + 43, dep3 = 11*60 + 19, dep4 = 12*60 + 47,
    dep5 = 14*60, dep6 = 15*60 + 45, dep7 = 19*60, dep8 = 21*60 + 45;

    printf("Enter a 12-hour time: ");
    int hours, mins, time;
    char pmAM;
    scanf("%d :%d %c", &hours, &mins, &pmAM);

    time = (((toupper(pmAM) == 'P' ? 12 : 0) + hours) * 60) + mins;
    
    if (time <= dep1 + (dep2 - dep1)/2)
    {
        printf("Closest depature time is 8.00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (time <= dep2 + (dep3 - dep2)/2)
    {
        printf("Closest depature time is 9.43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (time <= dep3 + (dep4 - dep3)/2)
    {
        printf("Closest depature time is 11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (time <= dep4 + (dep5 - dep4)/2)
    {
        printf("Closest depature time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (time <= dep5 + (dep6 - dep5)/2)
    {
        printf("Closest depature time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (time <= dep6 + (dep7 - dep6)/2)
    {
        printf("Closest depature time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (time <= dep7 + (dep8 - dep7)/2)
    {
        printf("Closest depature time is 7.00 p.m., arriving at 9:20 p.m.\n");
    }
    else
    {
        printf("Closest depature time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }
    /* Doesen't work well for time between d8 and d1, to be fixed later*/

    return 0;
}