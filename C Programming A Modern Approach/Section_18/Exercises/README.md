# Section 18 Exercise Solutions

### 1. For each of the following declarations, identify the storage class, type qualifiers, type specifiers, declarators, and initializers.
#### a) `static char **lookup(int level);`
storage class = static

type qualifier = none

type specifier = char **

declarator = lookup(int level)

initialiser = none

#### b) `volatile unsigned long io_flags;`
storage class = none

type qualifier = volatile

type specifier = unsigned long

declarator = io_flags

initialiser = none

#### c) `extern char *file_name[MAX_FILES], path[];`
storage class = extern

type qualifier = none

type specifier = char * []

declarator = file_name[MAX_FILES], path[]

initialiser = none

#### d) `static const char token_but[] = "";`

storage class = static

type qualifier = const

type specifier = char []

declarator = token_but[]

initialiser = ""

### 2. 
#### a) Which storage class is used primarily to indicate that a variable or function can be shared by several files?

extern

#### b) Suppose that a variable x is to be shared by serveral functions in one file but hidden from functions in other files. Which storage class should x be declared as?

static

#### c) Which storage classes can affect the storage duration of a variable?

extern and static

### 3. List the storage duration (static or automatic), scope (block or file), and linkage (internal, external, or none) of each variable and parameter in the following file:

    extern float a;

    void f(register double b)
    {
        static int c;
        auto char d;
    }

| Variable | Storage Dur. | Scope | Linkage |
| -------- | ------------ | ----- | ------- |
| a        | static       | file  | external|
| b        | automatic    | block | none    |
| c        | static       | block | none    |
| d        | automatic    | block | none    |

### 4. Let f be the following function. What will be the value of f(10) if f has never been called before? What will be the value of f(10) if f has been called five times previously.

    int f(int i)
    {
        static int j = 0;
        return i * j++;
    }

0 and 50.

### 5. State whether each of the following statements is true or false. Justify each answer.

#### a) Every variable with static storage duration has file scope.

False, static storage just means that it will remain in the same storage location during application runtime, block scope + static can exist.

#### b) Every variable declared inside a function has no linkage.

False, if a variable is declared with static outside a function, the extern storage class within a block will have internal or external linkage.

#### c) Every variable with internal linkage has static storage duration.

True, automatic storage duration has no linkage.

#### d) Every parameter has block scope.

True, parameters have block scope.

### 6. The following function is supposed to print an error message. Each message is preceded by an integer, indicating the number of times the function has been called. Unfortunately, the function always displays 1 as the number of the error message. Locate the error and show how to fix it without making any changes outside the function.

    void print_error(const char *message)
    {
        int n = 1;
        printf("Error %d: %s\n", n++, message);
    }

n must be declared static so that the function can retrieve it in the same place.

    void print_error(const char *message)
    {
        static int n = 1;
        printf("Error %d: %s\n", n++, message);
    }

### 7. Suppose that we declare x to be a const object. Which one of the following statements about x is false?

#### a) If x is of type int, it can be used as the value of a case label in a switch statement.
#### b) The compiler will check that no assignment is made to x.
#### c) x is subject to the same scope rules as variables.
#### d) x can be of any type.

a is false.

### 8. Write a complete description of the type of x as specified by each of the following declarations.

#### a) `char (*x[10])(int);`
#### b) `int (*x(int))[5];`
#### c) `float *(*x(void))(int);`
#### d) `void (*x(int, void (*y)(int)))(int);`

a) x is an array of pointers of a function with an int parameter that returns a char.

b) x is a function taking an int argument returning an array of 5 integers.

c) a function with no arguments which returns a pointer to a function with int argument, returning a float.

d) a function with 2 arguments, one of int and the other a pointer of a function with argument int, returning a void pointer. This is a pointer to a function with an int argument and returns nothing.

### 9. Use a series of type definitions to simplify each of the declarations in Exercise 8.
 
a) 

    typedef char Fcn(int);
    typedef Fcn *Fcn_ptr;
    typedef Fcn_ptr Fcn_ptr_array[10];

    Fcn_ptr_array x;

b) 

    typedef int Array[5];
    typedef Array Array_fcn(int);

    Array_ptr_fcn *x;

c) 

    typedef float *Fcn (int);
    typedef Fcn *Fcn_ptr (void);

    Fcn_ptr *x;

d) 

    typedef void Fcn (int);
    typedef void *arg_fcn (int);
    typedef Fcn *Fcn_ptr(int, arg_fcn);

    Fcn_ptr(x)

### 10. Write declarations for the following variables and functions


#### a) p is a pointer to a function with a character pointer argument that returns a character pointer.

    char *(*p)(char *));

#### b) f is a function with two arguments: p a pointer to a structure with tag t, and n, a long integer. f returns a pointer to a function that has no arguments and returns nothing.

    void *f(struct t *p)(long int n)(void);

#### c) a is an array of four pointers to functions that have no arguments and return nothing. The elements of a initially point to functions named insert, search, update and print.


    void (*a[])(void) = {insert, search, update, print};

#### d) b is an array of 10 pointers to functions with two int arguments that return structures with tag t.

    struct t (*b[10])(int, int);

### 11.
    
    int f(int)[];
    int *f(int);

    int g(int)(int);
    int (*g(int))(int);

    int a[10](int);
    int (*a[10])(int);

### 12. Write a complete description of the type of the function f, assuming that it's declarred as follows:

f is a function that takes the arguments of a pointer to a function taking long int argument and returning a float, with the other argument being a char pointer. f returns a pointer of a function of type int with the argument of a double.

