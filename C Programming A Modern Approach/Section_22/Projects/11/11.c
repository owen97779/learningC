#include <stdio.h>
#include <stdlib.h>

int day, month, year;
const char* months[12] = {"January", "February", "March", "April", 
                              "May", "June", "July", "August", "September", 
                              "October", "November", "December"};

void print_date(void);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Not inputted date in one string\n");
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%d%*[-/]%d%*[-/]%d", &month, &day, &year);
    printf("%s %.2d, %.4d\n", months[month-1], day, year);
    
    return 0;
}
