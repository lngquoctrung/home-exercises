# **TOPIC 05 - CHARACTER AND STRING**

## **1. Introduction**

In this lab tutorial, we'll introduce the C standard libray functions that manipulating string and character. These functions enable our program to process characters, strings, lines of text and block of memory.

## **2. Fundamental of String and Character**

String is a series of characters treated as a single unit. A string may include letters, digits and various special characters such as `+, -, *, /` and `$`. **String literals**, or **string constants**, in C are written in double quotation marks. For example, to represent a name, we declare as "John Smith", or a street address is "19 Nguyen Huu Tho Street".

A string in C is an array of characters ending in the null character (`'\0'`). A string is accessed via a pointer to the first character in the string. The value of a string is the address of its first character. Thus, in C, it's appropriate to say that a string is a pointer - in fact, a pointer to the string's first character. In this sense, strings are like arrays, because an array is also a pointer to its first element.

A *character array* or a *variable of type **char\**** can be initialized with a string in a definition. Each declaration initializes a variable to string `"blue"`. The first declaration creates an array with 5 elements, containing the characters: `'b'`, `'l'`, `'u'`, `'e'`, and `'\0'`. The second declaration creates a pointer variable `clrPtr` that points to the string `"blue"` somewhere in memory.

```C
char color[] = "blue";
char *clrPtr = "blue";
```

Printing a string that does not contain a terminating null character, `'\0'`, is an error. When storing a string of characters in a character array, be sure that the array is large enough to hold the largest string that will be stored.

## **3. Standard Input/output Library Functions**

This section presents several functions from the standard input/output library (`<stdio.h>`) specifically for manipulating character and string data. The following program will present an approach to read and assign an input string to array variable. We use functions `fgets`, `scanf` and `putchar` to read a line of text from the standard input (keyboard) and then, return the number of characters (string's length). Function `fgets` reads characters from the standard input into its first argument - an array of chars - until a newline or the end-of-file indicator in encountered, or until the maximum number of character is read. The maximum number of characters is one fewer than the value specified in `fgets`'s second argument. The third argument specifies the stream from which to read characters - in this case, we use the standard input stream (`stdin`). A null character (`'\0'`) is appended to the array when reading terminates.

```C
#include<stdio.h>
#define SIZE 100

int getLength(const char*);

int main(){
    char str[SIZE]; // create char array

    printf("Enter your name: ");
    fgets(str, SIZE, stdin);

    printf("String: %s\n", str);
    printf("String's length: %d", getLength(str));

    return 0;
}

int getLength(const char* str){
    if(str[0] == '\0') return 0;

    int length = 0;
    while(str[length] != '\0'){
        length = length + 1;
    }

    return length - 1; // exclude new line character
}
```

## **4. Character-Handling Library**

The character-handling library (`<ctype.h>`) includes several functions that perform useful tests and manipulations of character data. Each function receives an *unsigned char* (represented as an `int`). Characters are often manipulated as integers, because a character in C is a one-byte integer. Table below describes some useful functions to manipulate a character.

| *Prototype* | *Description* |
| :--        | :--           |
| `int isblank(int c);` | Returns a true value if `c` is a *blank character* that separates words in a line of text and 0 (`false`) otherwise. |
| `int isdigit(int c);` | Returns a true value if `c` is a *digit* and 0 (`false`) otherwise. |
| `int isalpha(int c);` | Returns a true value if `c` is a *letter* and 0 (`false`) otherwise. |
| `int isalnum(int c);` | Returns a true value if `c` is a *digit* or a *letter* and 0 (`false`) otherwise. |
| `int islower(int c);` | Returns a true value if `c` is a *lowercase letter* and 0 (`false`) otherwise. |
| `int isupper(int c);` | Returns a true value if `c` is a *uppercase letter* and 0 (`false`) otherwise. |
| `int tolower(int c);` | If `c` is an *uppercase letter*, `tolower` returns `c` as a *lowercase letter*. Otherwise, `tolower` returns the argument unchanged. |
| `int toupper(int c);` | If `c` is an *lowercase letter*, `toupper` returns `c` as a *uppercase letter*. Otherwise, `toupper` returns the argument unchanged. |

The program below illustrates these functions.

```C
#include<stdio.h>
#include<ctype.h>

int main(){
    printf("Is '8' digit? - %d\n", isdigit('8'));
    printf("Is 'A' digit? - %d\n", isdigit('A'));
    printf("Is 'a' in lower-case? - %d\n", islower('a'));

    printf("To lower-case of 'A' - %c\n", tolower('A'));
    printf("To upper-case of 'a' - %c\n", toupper('a'));

    return 0;
}
```

## **5. String-Handling Library**

The string-handling library (`<string.h>`) provides many useful functions for manipulating string data: copying strings, concatenating strings, adn comparing strings. Table below describes some popular function in `<string.h>` library.

| *Prototype* | *Description* |
| :--        | :--           |
| `char *strcpy(char *s1, const char *s2);` | Copies string $s_{2}$ into array $s_{1}$. The value of $s_{1}$ is returned. |
| `char *strncpy(char *s1, const char *s2, size_t n);` | Copies at most `n` characters of string $s_{2}$ into array $s_{1}$. The value of $s_{1}$ is returned. |
| `char *strcat(char *s1, const char *s2);` | Appends string $s_{2}$ into array $s_{1}$. The first character of $s_{2}$ overwrites the terminating null character of $s_{1}$. The value of $s_{1}$ is returned. |
| `char *strncat(char *s1, const char *s2, size_t n);` | Appends at most `n` characters of string $s_{2}$ into array $s_{1}$. The first character of $s_{2}$ overwrites the terminating null character of $s_{1}$. The value of $s_{1}$ is returned. |
| `char *strcmp(char *s1, const char *s2);` | Compares the string $s_{1}$ with the string $s_{2}$. The function returns 0, less than 0 or greater than 0 if $s_{1}$ is equal to, less than or greater than $s_{2}$, respectively. |
| `char *strncmp(char *s1, const char *s2, size_t n);` | Compares up to `n` characters of the string $s_{1}$ with the string $s_{2}$. The function returns 0, less than 0 or greater than 0 if $s_{1}$ is equal to, less than or greater than $s_{2}$, respectively. |

The program below illustrates these functions.

```C
#include<stdio.h>
#include<string.h>
#define SIZE 100

int main(){
    char str[] = "Happy New Year";
    char y[] = " 2017";
    char x[SIZE];

    strcpy(x, str);
    printf("x is copied: %s\n", x);

    printf("Compare x and str: %d\n", strcmp(str, x));

    printf("Concatenate y to x: %s\n", strcat(x, y));

    return 0;
}
```

## **6. Exercises**

1. Input a string and return the string's length.
2. Input a string and print it in reverse order.
3. Input a string represent a full name, split and print the first name and the last name.
4. Input a string and normalize it (strim the space before, insidem and afterm to lower each token except the first). For example, with the input "   PrOgRaMmInG    MeThOd   ". the output will be "Programming Method".
5. Input two string $s_{1}$ and $s_{2}$, concatenating $s_{2}$ to $s_{1}$. (Note: don't use `string.h` library).
6. Input a string and check whether a character appear or not. If yes, return the first position.
7. Input a string and check whether a character appears or not. If yes, return the all appearing positons.
8. Input a string and check whether a word appears or not. If yes, return the first postion.
9. Input two strings $s_{1}$ and $s_{2}$, return the first position where $s_{2}$ appears in $s_{1}$.
10. Input two strings $s_{1}$, $s_{2}$ and position. The insert $s_{2}$ to $s_{1}$ from this position.
11. Input a string and two integer numbers, named `n` and `position`. The delete `n` characters from `position` of input string.
