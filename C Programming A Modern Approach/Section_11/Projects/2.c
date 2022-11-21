#include <stdio.h>

int desired_time, departure_time, arrival_time;

int dep1 = 8*60, dep2 = 9*60 + 43, dep3 = 11*60 + 19, dep4 = 12*60 + 47,
dep5 = 14*60, dep6 = 15*60 + 45, dep7 = 19*60, dep8 = 21*60 + 45;

int arr1 = 10*60 + 16, arr2 = 11*60 + 52, arr3 = 13*60 + 31, arr4 = 15*60,
arr5 = 16*60 + 8, arr6 = 17*60 + 55, arr7 = 21*60 + 20, arr8 = 23*60 + 58;

void find_closest_flight(int, int *departure_time, int *arrival_time);

int main(void)
{
    printf("Enter a desired 24-hour time: ");
    int hours, mins;
    scanf("%d :%d",&hours,&mins);
    desired_time = hours * 60 + mins;

    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest depature time is %.2d:%.2d, arriving at %.2d:%.2d.\n", departure_time/60, departure_time%60, arrival_time/60, arrival_time%60);
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    if (desired_time <= dep1 + (dep2 - dep1)/2)
    {
        *departure_time = dep1;
        *arrival_time = arr1;
    }
    else if (desired_time <= dep2 + (dep3 - dep2)/2)
    {
        *departure_time = dep2;
        *arrival_time = arr2;
    }
    else if (desired_time <= dep3 + (dep4 - dep3)/2)
    {
        *departure_time = dep3;
        *arrival_time = arr3;
    }
    else if (desired_time <= dep4 + (dep5 - dep4)/2)
    {
        *departure_time = dep4;
        *arrival_time = arr4;
    }
    else if (desired_time <= dep5 + (dep6 - dep5)/2)
    {
        *departure_time = dep5;
        *arrival_time = arr5;
    }
    else if (desired_time <= dep6 + (dep7 - dep6)/2)
    {
        *departure_time = dep6;
        *arrival_time = arr6;
    }
    else if (desired_time <= dep7 + (dep8 - dep7)/2)
    {
        *departure_time = dep7;
        *arrival_time = arr7;
    }
    else
    {
        *departure_time = dep8;
        *arrival_time = arr8;
    }
    /* Doesen't work well for time between d8 and d1, to be fixed later*/
}