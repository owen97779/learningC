#include <stdio.h>

int main(void)
{
    int height = 8,
        length = 12,
        width = 10,
        volume = height * length * width;

    printf("The volume of the box is:%d\n",volume);
    printf("The weight of the box is:%d\n", (volume + 165)/166);
    
    return 0;
}