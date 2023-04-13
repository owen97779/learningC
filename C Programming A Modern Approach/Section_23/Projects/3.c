#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(void)
{
    int num_char;
    char buffer[BUFFER_SIZE];
    while((num_char = fread(buffer, sizeof(char), BUFFER_SIZE, stdin)) > 0)
    {
        char *p = strtok(buffer, " \t");
        while(p != NULL)
        {
            *p = toupper(*p);
            p = strtok(NULL, " \t");
        }

        //Remove the tokenisation of the strings with whitespace
        int i = 0;
        for(; i < num_char; i++)
        {
            if(buffer[i] == '\0')
                buffer[i] = ' ';
        }
        buffer[i] = '\0';

        fwrite(buffer, sizeof(char), num_char, stdout);
    }

    return 0;
}