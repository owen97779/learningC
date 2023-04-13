#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    FILE *fp;
    int itemNumber, day, month, year;
    float unitPrice;
    char file_buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        fprintf(stderr, "Single input file not provided\n");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error, file %s could not be opened\n", argv[1]); 
        exit(EXIT_FAILURE);
    }

    printf("\nItem\tUnit\tPurchase\n\tPrice\tDate\n");

    while(fgets(file_buffer, sizeof(file_buffer), fp))
    {
        if((sscanf(file_buffer, "%d,%f,%d%*[/-]%d%*[/-]%d", &itemNumber, &unitPrice, &month, &day, &year)) == 5)
        {
            printf("%d\t%.2f\t%.2d/%.2d/%.4d\n", itemNumber, unitPrice, month, day, year);
        }
        else
        {
            printf("Error, line not formatted correctly, skipping\n");
        }
    }
    
    fclose(fp);
    return 0;
}