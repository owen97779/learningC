#include <stdio.h>
#define PI 3.14159265358979323846f

int main(void)
{
    int radius = 10;
    float volume = (4.0f/3.0f)*PI*radius*radius*radius;
    printf("Volume is: %f",volume);
    
    return 0;
}