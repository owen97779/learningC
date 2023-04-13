#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 25

int main(void)
{
    FILE *fp, *fp2;
    char input_file[FILE_SIZE + 1], output_file[FILE_SIZE + 5];
    int c, shift;

    printf("Enter name of file to be encrypted: ");
    fgets(input_file, FILE_SIZE, stdin);
    input_file[strcspn(input_file, "\n")] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    if((fp = fopen(input_file, "r")) == NULL)
    {
        fprintf(stderr, "Error, could not open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    sprintf(output_file, "%s.enc", input_file);

    if((fp2 = fopen(output_file, "w")) == NULL)
    {
        fprintf(stderr, "Encrypted file could not be created\n");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(fp)) != EOF)
    {
        if(c <= 'Z' && c >= 'A')
        {
            fputc(((c - 'A') + shift) % 26 + 'A', fp2);
        }
        else if(c <= 'z' && c >= 'a')
        {
            fputc(((c - 'a') + shift) % 26 + 'a', fp2);
        }
        else
        {
            fputc(c, fp2);
        }
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
