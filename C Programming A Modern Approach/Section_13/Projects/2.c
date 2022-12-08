/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[13], msg_str[MSG_LEN + 1];
    int month, day, i, j, num_remind = 0, hours, mins;

    for(;;)
    {
        if(num_remind == MAX_REMIND)
        {
            printf("-- No Space Left -- \n");
            break;
        }

        printf("Enter reminder 'mm/dd hh:mm message': ");
        scanf(" %2d/ %2d", &month, &day);
        if(day == 0 || month == 0)
        {
            break;
        }

        else if(day < 0 || day > 31 || month > 12)
        {
            printf("-- Day is out of scope --\n");
            while(getchar() != '\n'); /* Discards the remaining characters*/
            continue;
        }

        scanf("%d: %d", &hours, &mins);
        sprintf(day_str, "%2d %2d %.2d:%.2d ", month, day, hours, mins);
        read_line(msg_str, MSG_LEN - 13);

        for (i = 0; i < num_remind; i++)
        {
            if(strcmp(day_str, reminders[i]) < 0)
            {
                break;
            }
        }
        for(j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth Day Time\tReminder\n");
    for(i = 0; i < num_remind; i++)   
    {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i < n)
        {
            str[i++] = ch;
        }    
    }
    str[i] = '\0';
    return i;
}