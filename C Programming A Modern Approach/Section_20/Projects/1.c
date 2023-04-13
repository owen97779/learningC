#include <stdio.h>

int main(void)
{
    union float_value {
        float number;
        struct IEEE{
            unsigned int fraction: 23;
            unsigned int exponent: 8;
            unsigned int sign: 1;
        }float_IEEE;
    };

    union float_value var;

    var.float_IEEE.sign = 1;
    var.float_IEEE.exponent = 128;
    var.float_IEEE.fraction = 0;

    printf("%f\n", var.number);
    printf("%d\n", var.float_IEEE.sign);
    printf("%d\n", var.float_IEEE.exponent);
    printf("%d\n", var.float_IEEE.fraction);

    return 0;
}