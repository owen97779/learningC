/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char **argv)
{
  FILE *input_file, *output_file;
  char word[MAX_WORD_LEN+2];
  char c;
  int word_len;

  if(argc != 3)
  {
    fprintf(stderr, "Error, input and output files not provided");
    exit(EXIT_FAILURE);
  }

  if(((input_file = fopen(argv[1], "r")) == NULL) || ((output_file = fopen(argv[2], "w")) == NULL))
  {
    fprintf(stderr, "Error, files could not be opened");
    exit(EXIT_FAILURE);
  }
  
  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1, input_file);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(output_file);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(output_file);
      clear_line();
    }
    add_word(word);
  }
}