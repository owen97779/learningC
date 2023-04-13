/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char **argv)
{
  FILE *input, *output;
  unsigned char buffer[10];

  if(argc != 3)
  {
    fprintf(stderr, "Error, not provided input and output files\n");
    exit(EXIT_FAILURE);
  }

  if(((input = fopen(argv[1], "rb")) == NULL) || ((output = fopen(argv[2], "wb")) == NULL))
  {
    fprintf(stderr, "Error, files could not be opened");
    exit(EXIT_FAILURE);
  }

  size_t n, m;

  while ((n = fread(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), input))) 
  {
    for(int i = 0; i < n; i++)
    {
      buffer[i] = buffer[i] ^ KEY;
    }
    
    m = fwrite(buffer, sizeof(buffer[0]), n, output);
    if (m != n) { //Checks if fwrite failed
      fprintf(stderr, "Error writing to output file\n");
      exit(EXIT_FAILURE);
    }
  }

  fclose(input);
  fclose(output);

  return 0;
}
