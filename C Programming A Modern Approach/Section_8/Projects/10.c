#include <stdio.h>
#define SIZE ((sizeof(array))/sizeof(array[0]))

int main(void)
{
    int array[8] = {8*60, 9*60 + 43, 11*60 + 19, 12*60 + 47, 14*60, 15*60 + 45, 19*60, 21*60 + 45},
    arrival[8] = {10*60 + 16, 11*60 + 52, 13*60 + 31, 15*60, 16*60 + 8, 17*60 + 55, 21*60 + 20, 23*60 +58},
    i;

    printf("Enter a 24-hour time: ");
    int hours, mins;
    scanf("%d :%d",&hours,&mins);

    for(i = 0; i < SIZE - 1 && hours * 60 + mins >= array[i] + (array[i+1] - array[i]) / 2; i++);

    printf("Closest depature time is %d:%d, arriving at %d:%d", array[i]/60, array[i]%60, arrival[i]/60, arrival[i]%60);
    
    return 0;
}