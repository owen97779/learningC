/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* canopen.c (Chapter 22, page 547) */
/* Checks whether a file can be opened for reading */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  bool failed = false;

  for(int i = 1; i < argc; i++)
  {
    if ((fp = fopen(argv[i], "r")) == NULL) 
    {
        fprintf(stderr, "%s can't be opened\n", argv[i]);
        failed = true;
    }
    else
    {
        printf("%s can be opened\n", argv[i]);
    }
    fclose(fp);
  }

  if(failed)
  {
    exit(EXIT_FAILURE);
  }

  return 0;
}