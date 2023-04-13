# Section 23 Exercises

### 1. Extend the `round_nearest` function so that it rounds a floating-point number *x* to *n* digits after the decimal point. For example, the call `round_nearest(3.14159, 3) would return 3.142.


    #include <math.h>
    #include <stdio.h>

    float round_nearest(float x, int n)
    {
        double intpart, power = pow(10, n);
        return modf(x * power, &intpart) < 0.5 ? floor(x * power) / power : ceil(x * power) / power;
    }

    int main(void)
    {
        printf("%f\n", round_nearest(3.14159, 3));
    }


### 2. (C99) Write the following function:

    double evaluate_polynomial(double a[], int n, double x);

### The function should return the value of the polynomial anxn + an-1xn-1 + ... + a0, where the ai's are stored in corresponding elements of the array a, which has length n + 1. Have the function use Horner's Rule to compute the value of the polynomial:

    ((...((anx + an-1)x + an-2)x + ...)x + a1)x + a0

### Use the fma function to perform the multiplications and additions.

    double evaluate_polynomial(double a[], int n, double x)
    {
        double result = a[0];
        for(int i = 1; i < n; i++)
        {
            result = fma(result, x, a[i]);
        }
        return result;
    }

### 3. (C99) Check the documentation for your compiler to see if it performs contraction on arithmetic expressions and, if so, under what circumstances.

Floating-point contraction is when two or more mathematical operations are combined as a single operation, such as the `fma` function. In GCC, the optimisation `-ffp-contract=fast` allows the compiler to do contractions with FMA instructions.

### 4. Using isalpha and isalnum, write a function that checks whether a string has the syntax of a C identifier (it consists of letters, digits and underscores, with a letter or underscore at the beginning).

    include <ctype.h>
    include <stdbool.h>

    bool identifier(char *string)
    {
        if (!isalpha(*string) && (*string != '_'))
            return false;
        string++;
        for(; *string != '\0'; string++)
        {
            if(!isalnum(*string) && (*string != '_'))
            {
                return false;
            }
        }
        return true;
    }

### 5. Using isxdigit, write a function that checks whether a string represents a valid hexadecimal number (it consists solely of hexadecimal digits). If so, the function returns the value of the number as a long int. Otherwise, the function returns -1.

    #include <ctype.h>

    long int hexadecimal(char *string)
    {
        long int value = 0;
        for(; *string != '\0'; string++)
        {
            if(!isxdigit(*string))
            {
                return -1;
            }
            if(isdigit(*string))
            {
                value += *string;
            }
            else
            {
                value += toupper(*string) - 'A' + 10;
            }
        }
        return value;
    }

### 6. In each of the following cases, indicate which function would be the best to use: memcpy, memmove, strcpy or strncpy. Assume that the indicated action is to be performed by a single function call.

#### a) Moving all elements of an array "down" one position in order to leave room for a new element in position 0.

`memmove`

#### b) Deleting the first character in a null-terminated string by moving all other characters back one position.

`memmove`

#### c) Copying a string into a chracter array that may not be large enough to hold it. If the array is too small, assume that the string is to be truncated; no null character is necessary at the end.

`strncpy`

#### d) Copying the contents of one array variable into another.

`memcpy`

### 7. Section 23.6 explains how to call `strchr` repeatedly to locate all occurrences of a character within a string. Is it possible to locate all occurrences in reverse order by calling `strrchr` repeatedly?

    char *p, str[] = "Form follows function";
    p = strrchr(str, 'f');
    while(p != NULL)
    {
        p = strrchr(p - 1, 'f');
    }

I could not get it to work like this without modifying the original string, this is because strrchar requires use of a null character to traverse.

### 8. Use strchr to write the following function:

    int numchar(const char *s, char ch);

### numchar returns the number of times each character ch occurs in the string s.

    int numchar(const char *s, char ch)
    {
        int numchar = 0;
        char *p = strchr(s, ch);
        while(p != NULL)
        {
            numchar++;
            p = strchr(p + 1, ch);
        }
        return numchar;
    }

### 9. Replace the test condition in the following if statement by a single call of strchr:

    if (ch == 'a' || ch == 'b' || ch == 'c') ...



    if (strchr("abc", ch) != NULL)
    {
        ...
    }

