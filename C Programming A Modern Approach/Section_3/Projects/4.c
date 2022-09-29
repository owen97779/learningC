#include <stdio.h>

int main(void)
{
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    int first, second, third;
    scanf("(%d )%d-%d",&first,&second,&third);
    printf("You entered: %d.%d.%d\n", first,second,third);

    return 0;
}