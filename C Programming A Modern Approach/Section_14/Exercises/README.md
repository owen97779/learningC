# Section 14 Exercise Solutions

### 1. Write parameterized macros that compute the following values.
#### a) The cube of x.
    #define CUBE(x) x*x*x
#### b) The remainder when n is divided by 4.
    #define REMAINDER(n) (n % 4)
#### c) 1 if the product of x and y is less than 100, 0 otherwise.
    #define PROD(x,y) (x * y < 100 ? 1 : 0)

### 2. Write a macro **NELEMS(a)** that computes the number of elements in a one-dimensional array **a**.
    #define NELEMS(a) (sizeof(a) / sizeof(a[0]))

### 3. Let **DOUBLE** be the following macro:
    #define DOUBLE(x) 2*x
#### a) What is the value of **DOUBLE(1+2)**?
The answer is: 4
#### b) What is the value of **4/DOUBLE(2)**?
The answer is: 4
#### c) Fix the following definition of **DOUBLE**.
    #define DOUBLE(x) (2*(x))

### 4. For each of the following macros, give an example that illustrates a problem with the macro and how to fix it.
#### a) **#define AVG(x,y) (x+y)/2**
First problem is the order of operations, **1/AREA(x,y)** would result in **1/x*y** rather than **1/((x+y)/2)**. Placing parentheses around the entire definition should fix this problem.

Second problem is the missing parentheses in each argument. A statement such as **AVG(a>b,c<d)** would result in **(a>(b+c)<d)/2** rather than **((a>b)+(c<d))/2**. Placing parentheses around each argument should fix this problem.

    #define AVG(x,y) (((x)+(y))/2)
#### b) **#define AREA(x,y) (x)*(y)**
Same initial problem in the order of operations, placing parentheses around the definition should fix it.

    #define AREA(x,y) ((x) * (y))


### 5. Let **TOUPPER** be the following macro.
    #define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
Let **s** be a string and let **i** be an **int** variable. Show the output produced by each of the following program fragments.
#### a) 

    strcpy(s, "abcd");
    i=0;
    putchar(TOUPPER(s[++i]));
**Output**: D

#### b) 
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]))
**Output**: 3

### 6. 
#### a) Write a macro **DISP(f,x)** that expands into a call of **printf** that displays the value of the function **f** when called with the argument **x**. For example, 
**DISP(sqrt, 3.0)**

should expand into

**printf("sqrt (%g) = %g\n" 3.0, sqrt(3.0));**

    #define DISP(f,x) printf(#f "(%g) = %g\n", (x), f(x))


#### b) Write a macro **DISP2(f,x,y)** that's similar to **DISP** but works for functions with two arguments.
    #define DISP2(f,x,y) printf(#f "(%g, %g) = %g\n", (x), (y), f((x),(y)))

### 7. Let **GENERIC_MAX** be the following macro:
    #define GENERIC_MAX(type)       \
    type type##_max(type x, type y) \
    {                               \
        return x > y ? x : y;       \
    }                               \
#### a) Show the preprocessor's expansion of **GENERIC_MAX(long)**.
    long long_max(long x, long y)
    {
        return x > y ? x : y;
    }
#### b) Explain why GENERIC_MAX doesn't work for basic types such as **unsigned long**.
Type with a space in the name will not work as the token operator **##** will include a space in the name preventing a function to be created.
    
    unsigned long unsigned long_max(unsigned long x, unsigned long y)

#### c) Describe a technique that would allow us to use GENERIC_MAX with basic types.

    typdef unsigned long u_long;

### 8. Suppose we want a macro that expands into a string containing the current line number and file name, In other words, we'd like to write
    const char *str = LINE_FILE;

and have it expand into 

    const char *str ="Line 10 of file foo.c";

where **foo.c** is the file containing the program and 10 is the line on which the invocation of **LINE_FILE** appears. 

    #define STRINGIZE(x) #x
    #define EXPAND(x) STRINGIZE(x)
    #define LINE_FILE "Line " EXPAND(__LINE__) " of file " __FILE__

### 9. Write the following parameterized macros.
#### a) **CHECK(x,y,n)** - Has the value 1 is both x and y fall between 0 and n - 1, inclusive.
    #define CHECK(x,y,n) (((x)>=0&&(x)<=(n)-1&&(y)>=0&&(y)<=(n)-1)?1:0)
#### b) **MEDIAN(x,y,x)** - Finds the median of x, y and z.
    #define MEDIAN(x,y,z) ((x) >= (y) && (x) <= (z) ? x : ((y) >= (x) && (y) <= (z) ? (y) : (z)))

#### c) **POLYNOMIAL(x)** - Computes the polynomial
    #define POLYNOMIAL(x) ((3*(x)*(x)*(x)*(x)*(x)) \
                        + (2*(x)*(x)*(x)*(x))     \
                        - (5*(x)*(x)*(x))         \
                        - ((x)*(x))               \
                        + (7*(x))                 \
                        - 6)

### 10. Functions can often - but not always - be written as parameterized macros. Discuss what characteristics of a function would make it unsustainable as a macro.

Although a macro invocation looks the same as a function call, errors can be caused when calling an argument more than once. Therefore, recursive functions or special arguments (such as (++)) can cause side effects.

### 11. (C99) C programmers often use the **fprintf** function to write error messages:
**fprintf(stderr, "Range error: index = %d\n", index);**

**stderr** is C's "standard error" stream; the remaining arguments are the same ass those for **printf**, starting with the format string. Write a macro named **ERROR** that generates the call of **fprintf** shown above when given a format string and the items to be displayed:

**ERROR("Range error: index = %d\n", index);**

    #define ERROR(s,...) (fprintf(stderr, (s), __VA_ARGS__))

### 12. Suppose that the macro **M** has been defined as follows:
    #define M 10

Which of the following tests will fail?
#### a) **#if M**
#### b) **#ifdef M**
#### c) **#ifndef M**
#### d) **#if defined(M)**
#### e) **#if !defined(M)**


**c)** and **e)** will fail because **M** is defined.

### 13. a) Show that the follwing program will look like after preprocessing. You may ignore any lines added to the program as a result of including the <stdio.h> header.

    #include <stdio.h>

    #define N 100

    void f(void);

    int main(void)
    {
        f();
    #ifdef N
    #undef N
    #endif
        return 0;
    }

    void f(void)
    {
    #if defined(N)
        printf("N is %d\n", N);
    #else
        printf("N is undefined\n");
    #endif
    }

After preprocessing:
    
    void f(void);

    int main(void)
    {
        f();    
        return 0
    }

    void f(void)
    {
        printf("N is undefined\n");
    }

b) Output:
**"N is undefined\n"**

### 14. Show what the following program will look like after preprocessing. Some lines of the program may cause compilation errors; find all such errors.

    #define N = 10
    #define INC(x) x+1
    #define SUB(x,y) x-y
    #define SQR(x) ((x)*(x))
    #define CUBE(x) (SQR(x)*(x))
    #define M1 (x,y) x##y
    #define M2 (x,y) #x #y

    int main(void)
    {
        int a[N], i, j, k, m;
    #ifdef N
        i = j;
    #else 
        j = i;
    #endif

        i = 10 * INC(j);
        i = SUB(j, k);
        i = SQR(SQR(j));
        i = CUBE(j);
        i = M1(j, k);
        puts(M2(i, j));

    #undef SQR
        i = SQR(j);
    #define SQR
        i = SQR(j);

        return 0;
    }

### 15. Suppose that a program needs to display messages in either English, French, or Spanish. Using conditional compilation, write a program fragment that displays one of the following three messages, depending on whether or not the specified macro is defined.

**Insert Disk 1** (if **ENGLISH** is defined)

**Inserez Le Disque 1** (if **FRENCH** is defined)

**Inserte El Disco 1** (if **SPANISH** is defined)

    /* Define a macro with the name FRENCH OR SPANISH #define ... */
    
    #ifdef FRENCH
    printf("Inserez Le Disque 1\n");
    #ifdef SPANISH
    printf("Inserte El Disco 1\n");
    #else 
    printf("Insert Disk 1\n");
    #endif

### 16. (C99) Assume that the following macro definitions are in effect:

**#define IDENT(x) PRAGMA(ident #x)**

**#define PRAGMA(x) _Pragma(#x)**

What will the following line look like after macro expansion?

**IDENT(foo)**

    #pragma ident "foo"

