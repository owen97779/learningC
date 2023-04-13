#include <stdio.h>

int main(void)
{
    struct times{
        int departure;
        int arrival;
    } times[8];

    times[0].departure = 8*60;
    times[1].departure = 9*60 + 43;
    times[2].departure = 11*60 + 19;
    times[3].departure = 12*60 + 47;
    times[4].departure = 14*60;
    times[5].departure = 15*60 + 45;
    times[6].departure = 19*60;
    times[7].departure = 21*60 + 45;

    times[0].arrival = 10*60 + 16;
    times[1].arrival = 11*60 + 52;
    times[2].arrival = 13*60 + 31;
    times[3].arrival = 15*60;
    times[4].arrival = 16*60 + 8;
    times[5].arrival = 17*60 + 55;
    times[6].arrival = 21*60 + 20;
    times[7].arrival = 23*60 + 58;

    printf("Enter a 24-hour time: ");
    int hours, mins;
    scanf("%2d :%2d",&hours,&mins);
    
    int i;
    for(i = 0; i < 8; i++)
    {   
        if(hours*60 + mins <= times[i].departure + (times[i+1].departure - times[i].departure)/2)
        {
            break;
        }
    }
    printf("Closest departure time is %02d:%02d, arriving at %02d:%02d.\n", times[i].departure / 60, times[i].departure % 60, times[i].arrival / 60, times[i].arrival % 60);

    return 0;
}