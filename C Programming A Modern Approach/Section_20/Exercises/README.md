# Section 20 Exercise Solutions

### 1. Show the output produced by each of the following program fragments. Assume that i, j and k are unsigned short integers.
#### a) `i = 8; j = 9;`
#### `printf("%d", i >> 1 + j >> 1);`

0.

#### b) `i = 1;`
#### `printf("%d", i & ~i);`

0.

#### c) `i = 2; j = 1; k = 0;`
#### `printf("%d", ~i = & j ^ k);`

0.

#### d) `i = 7; j = 8; k = 9;`
#### `printf("%d", i ^ j & k);`

15.

### 2. Describe a simple way to "toggle" a bit. Illustrate this technique by writing a statement that toggles bit 4 of the variable i.


    /* Give i any value */
    short int i = 0x011A;
    /* Xor i with the constant 0x0010, which is equivalent to 1 << 4 */
    i ^= 1 << 4;

### 3. Explain what effect the following macro has on its argument. You may assume that the arguments have the same type.

`#define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))`

Swaps the values of x and y.

### 4. In computer graphics, colors are often stores as three numberes, representing red, green and blue intensities. Suppose that each number requires eight bits, and we'd like to store all three values in a single long integer. Write a macro named MK_COLOR with three parameters (the red, green and blue intensities). MK_COLOR should return a long in which the last three bytes contain the red, green and blue intensities, with the red value as the last byte and the green value as the next-to-last byte.

    #define MK_COLOR(red,green,blue) (long int (blue) >> 16 | (green) >> 8 | (red)) 

### 5. Write macros named GET_RED, GET_GREEN, GET_BLUE that returns it's 8 bit red, green and blue intensities.

    #define GET_RED(x) (x & 0xff)
    #define GET_GREEN(x) ((x >> 8) & 0xff)
    #define GET_BLUE(x) ((x >> 16) & 0xff)

### 6. Use the bitwise operators to write the following function:

`unsigned short swap_bytes(unsigned short i);`

### swap_bytes should return the number that results from swapping the two bytes in i (Short integers occupy two bytes on most computers). For example, if i has the value 0x1234 (00010010 00110100 in binary), then swap_bytes should return 0x3412 (00110100 00010010 in binary). Test your function by writing a program that reads a number in hexadecimal, then writes the number with its bytes swapped:

    unsigned short swap_bytes(unsigned short i)
    {
        return (i << 8) + (i >> 8);
    }

### 7. Write the following functions:

`unsigned int rotate_left(unsigned int i, int n);`

`unsigned int rotate_right(unsigned int i, int n);`
### rotate_left should return the result of shifting the bits in i to the left by n places, with the bits that were "shifted off" moved to the right end of i (For example, the call rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32 bits long). rotate_right is similar, but it should "rotate" bits to the right instead of the left.

    unsigned int rotate_left(unsigned int i, int n)
    {
        return (i << n) | (i >> (sizeof(unsigned int) * 8) - n);
    }

    unsigned int rotate_right(unsigned int i, int n)
    {
        return (i << (sizeof(unsigned int) * 8) - n) | (i >> n);
    }

### 8. Let f be the following function

    unsigned int f(unsigned int i, int m, int n)
    {
        return (i >> (m + 1 - n)) & ~(~0 << n);
    }

#### a) What is the value of `~(~0 << n)`?

Returns a number with the rightmost n bits set to 1 and the others set to 0.

#### b) What does this function do?

Returns n section of bits within i from the position m + 1 to the position m + 1 - n.

### 14. When stored according to the IEEE floating-point standard, a float value consists of a 1-bit sign (the leftmost -- or most significant -- bit), an 8-bit exponent, and a 23-bit fraction, in that order. Design a structure type that occupies 32 bits, with bit-field members corresponding to the sign, exponent, and fraction. Declare the bit-fields to have type unsigned int. Check the manual for your compiler to determine the order of the bit-fields.

    struct float_value{
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;        
    }


