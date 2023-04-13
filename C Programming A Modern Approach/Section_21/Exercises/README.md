# Section 21 Exercise Solutions

### 1. Locate where header files are kept on your system. Find the nonstandard headers and determine the purpose of each.

There are a lot of header files in my clang 14.0.0 compiler, many of which are used in different C standards. It can be found in `/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include`.

### 2. Having located the header files on your system, find a standard header in which a macro hides a function.

### 3. When a macro hides a function, which must come first in the header file: the macro definition or the function prototype? Justify your answer.

The preprocessor must be aware that there is a function with a matching name therefore the prototype must appear before the macro definition.

### 4. Make a list of all reserved identifiers in the "future library directions" section of the C99 standard. Distinguish between identifiers that are reserved for use only when a specific header is included versus identifiers that are reserved for use as external names.

...

### 5. The islower function, which belongs to <ctype.h>, tests whether a character is a lower-case letter. Why would the following macro version of islower not be legal according to the C standard? (You may assume that the character set is ASCII.)

A paramaterised macro must:
1. Be fully protected by parenthesis.
2. Evaluate its argument exactly once.

Unfortunately, this version of islower is not legal as it violates the second rule. Hence leading to unintended consequences, especially when using postfix operator as an example.

### 6. The <ctype.h> header usually defines most of its functions as macros as well. These macros rely on a static array that's declared in <ctype.h> but defined in a separate file. A portion of a typical <ctype.h> header appears below. Use this sample to answer the following questions.

#### a) Why do the names of the "bit" macros (such as _UPPER) and the _ctype array begin with an underscore?

They are used to indicate that they are implementation specific / reserved for use in the header with file scope within the standard C library. This prevents programmers from having naming conflicts with their own macros/functions. 

#### b) Explain what the _ctype array will contain. Assuming that the character set is ASCII, show the values of the array elements at positions 9 (the horizontal tab character), 32 (the space character), 65 (the letter A) and 94 (the ^ character). See Section 23.5 for a description of what each macro should return.

The _ctype array is an array of 256 integers arranged in bitfield form, each bit represents the property of the character that is passed through.

In the book, uppercase (_UPPER) is defined as the first bit 0, lowercase the second 1...

_ctype[9] corresponds to ('\t') which is a _SPACE character 0x20 = 0b100000.

_ctype[32] corresponds to the space character _SPACE 0x20 = 0b100000.

_ctype[65] corresponds to an upper-case character _UPPER 0x01 = 0b1.

_ctype[94] corresponds to a punctuation character _PUNCT 0x10 = 0b10000.

#### c) What is the advantage of using an array to implement these macros?

Quick to lookup values in an array.

### 7. In which standard header would you expect to find each of the following?

#### a) A function that determines the current day of the week.

<time.h>

#### b) A function that tests whether a character is a digit.

<ctype.h>

#### c) A macro that gives the largest unsigned int value

<limits.h> 

#### d) A function that rounds a floating-point number to the next highest integer

<math.h>

#### e) A macro that specifies the number of bits in a character

<limits.h>

#### f) A macro that specifies the number of significant digits in a double value

<float.h>

#### g) A function that searches a string for a particular character

<string.h>

#### h) A function that opens a file for reading

<stdio.h>