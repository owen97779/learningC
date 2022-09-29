#include <stdio.h>

int main(void)
{
    int GS1, groupID, pubCode, itemNumber, checkDig;
    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &GS1, &groupID, &pubCode, &itemNumber, &checkDig);
    
    printf("GS1 prefix: %d\nGroup Identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",GS1,groupID,pubCode,itemNumber,checkDig);
   
    return 0;
}