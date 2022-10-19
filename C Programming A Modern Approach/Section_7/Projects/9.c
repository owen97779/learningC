#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, mins; 
    char amPM;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hours, &mins, &amPM);

    if (hours == 12)
    {
        hours = 0;
    }

    printf("Equivalent 24-hour time: %02d:%02d", ((toupper(amPM) == 'P' ? 12 : 0) + hours), mins);

    return 0;

}