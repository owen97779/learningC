#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
#define MAX_FILE_NAME 20
#define BUFFER_SIZE sizeof(struct part)

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

void print(void);
void merge_files(void);

int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'p': print();
                break;
      case 'm': merge_files();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }

  return 0;
}

void print(void)
{
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand);
}

void merge_files(void)
{
    FILE *fp1, *fp2;
    char file1[MAX_FILE_NAME + 1];
    char file2[MAX_FILE_NAME + 1];
    struct part part1;
    struct part part2;

    printf("Enter name of the first file to merge: ");
    read_line(file1, MAX_FILE_NAME);
    printf("Enter name of the second file to merge: ");
    read_line(file2, MAX_FILE_NAME);

    if(((fp1 = fopen(file1, "rb")) == NULL) || ((fp2 = fopen(file2, "rb")) == NULL))
    {
        fprintf(stderr, "Files could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    int inventory_num1 = fread(&part1, sizeof(struct part), 1, fp1);
    int inventory_num2 = fread(&part2, sizeof(struct part), 1, fp2);

    while((inventory_num1 == 1) && (inventory_num2 == 1))
    {
        if(part1.number < part2.number)
        {
            inventory[num_parts++] = part1;
            inventory_num1 = fread(&part1, sizeof(struct part), 1, fp1);
        }
        
        else if(part2.number < part1.number)
        {
            inventory[num_parts++] = part2;
            inventory_num2 = fread(&part2, sizeof(struct part), 1, fp2);
        }

        else
        {
            if(strncmp(part1.name, part2.name, NAME_LEN) == 0)
            {
                //Just copy part1 with the extra on_hand from part2
                part1.on_hand += part2.on_hand;
                inventory[num_parts++] = part1;
            }
            else
            {
                fclose(fp1);
                fclose(fp2);
                fprintf(stderr, "Part names %s and %s do not match\n", part1.name, part2.name);
                exit(EXIT_FAILURE);
            }
            inventory_num1 = fread(&part1, sizeof(struct part), 1, fp1);
            inventory_num2 = fread(&part2, sizeof(struct part), 1, fp2);
        }
    }

    while(inventory_num1 == 1)
    {
        inventory[num_parts++] = part1;
        inventory_num1 = fread(&part1, sizeof(struct part), 1, fp1);
    }
    
    while(inventory_num2 == 1)
    {
        inventory[num_parts++] = part2;
        inventory_num2 = fread(&part2, sizeof(struct part), 1, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}