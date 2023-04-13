#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 20

int compare_strings(const void *a, const void *b);

int main(void)
{
    int num_of_strings = 0;
    char **strings = NULL;
    char string[MAX_WORD_LEN + 1];

    for (;;)
    {
        printf("Enter word: ");
        if (fgets(string, MAX_WORD_LEN + 1, stdin) == NULL)
        {
            break;
        }
        if (string[0] == '\n')
        {
            break;
        }
        if (string[strlen(string) - 1] == '\n')
        {
            string[strlen(string) - 1] = '\0';
        }

        num_of_strings++;
        strings = (char **) realloc(strings, num_of_strings * sizeof(char *));
        if (strings == NULL)
        {
            printf("Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        strings[num_of_strings - 1] = (char *) malloc(strlen(string) + 1);
        if (strings[num_of_strings - 1] == NULL)
        {
            printf("Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(strings[num_of_strings - 1], string);
    }

    qsort(strings, num_of_strings, sizeof(strings[0]), compare_strings);
    printf("Sorted words:\n");
    for (int i = 0; i < num_of_strings; i++)
    {
        printf("%s ", strings[i]);
        free(strings[i]);
    }
    printf("\n");
    free(strings);
    return 0;
}

int compare_strings(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
