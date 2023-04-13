# Section 22 Exercises

### 1. Indicate whether each of the following files is more likely to contain text data or binary data:

#### a) A file of object code produced by a C compiler.

Binary data.

#### b) A program listing produced by a C compiler.

Text data.

#### c) An email message sent from one computer to another.

Text data.

#### d) A file containing graphics image.

Binary data.

### 2. Indicate which mode string is most likely to be passed to fopen in each of the following situations:

#### a) A database management system opens a file containing records to be updated.

"rb+"

#### b) A mail program opens a file of saved messages so that it can add additional messages to the end.

"a+"

#### c) A graphics program opens a file containing a picture to be displayed on screen.

"rb"

#### d) An operating system command interpreter opens a 'shell script' (or 'batch file') containing commands to be executed.

"r"

### 3. Find the error in the following program fragment and show how to fix it.

    FILE *fp;

    if (fp = fopen(filename, "r))
    {
        /* Read characters until end-of-file */
    }
    fclose(fp);

Code fragment does not check if file can be opened.

    FILE *fp;

    if ((fp = fopen(filename, "r)) == NULL)
    {
        fprintf(stderr, "Error, file %s cannot be opened\n", filename);
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Read characters */
    }
    fclose(fp);

### 4. Show how each of the following numbers will look if displayed by `printf` with `%#012.5g` as the conversion specification.

#### a) 83.7361

00000083.736

#### b) 29748.6607

002.9749e+04

#### c) 1054932234.0

001.0549e+09

#### d) 0.0000235218

002.3522e-05

### 5. Is there any difference between the `printf` conversion specifications `%.4d` and `%04d`? Is so, explain what it is.

No difference, both pads the integer to 4 digits with leading zeros if the integer has less than 4 digits.