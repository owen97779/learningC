#include <stdio.h>

int main(void)
{
    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10,&n11);

    printf("Check digit: %d", 9 - (((3*(n1+n3+n5+n7+n9+n11)+n2+n4+n6+n8+n10)) - 1) % 10);
    
    return 0;
}
