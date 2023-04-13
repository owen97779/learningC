#include <stdio.h>
#include <stdlib.h>

#define INTEGERS 10000

int cmpfunc(const void *a, const void *b);

int main(int argc, char **argv)
{
    FILE *fp;
    int int_array[INTEGERS];
    int i = 0;
    float median;

    if(argc != 2)
    {
        fprintf(stderr, "Error, file not provided");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error, could not open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(!feof(fp) && i < INTEGERS)
    {
        fscanf(fp, " %d", &int_array[i++]);
    }
    i--;

    qsort(int_array, i, sizeof(int), cmpfunc);

    //if i is odd (i+1)/2, even (i/2 + i/2 + 1) / 2

    if((i - 1) % 2 == 0)
    {
        median = (int_array[(i - 1) / 2] + int_array[(i - 1)/ 2 + 1]) / 2.0;
        
    }
    else
    {
        median = (int_array[(i - 1) / 2]);
    }

    printf("Smallest: %d\nLargest: %d\nMedian: %.1f\n", int_array[0], int_array[i], median);
    fclose(fp);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
