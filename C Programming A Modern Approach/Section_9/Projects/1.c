#include <stdio.h>
#define arraySize 20

void selection_sort(int a[], int);

int main(void)
{
    int i, array[arraySize] = {0}, count = 0, number;
    
    printf("Enter a series of numbers: ");
    for(i = 0; i < arraySize; i++)
    {
        scanf(" %d", &number);
        array[i] = number;
        count++;
        if(getchar() == '\n')
        {
            break;
        }
    }

    printf("Unsorted series of numbers: ");
    for(i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\nSorted series of numbers: ");
    selection_sort(array, count);
    for(i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n == 0) return;
    
    int i, index_largest = 0;

    for (i = 1; i < n; i++) {
        if (a[i] > a[index_largest])
            index_largest = i;
    }

    int largest = a[index_largest];
    a[index_largest] = a[n-1];
    a[n-1] = largest;

    selection_sort(a, n - 1);
}