# **TOPIC 09 - FILE I/O**

## **1. Introduction**

Before this lab, all inputs to your program are from keyboard, using scanf function, and output the screen, using printf function. In this lab, we'll introduce another way to interact with your program by using file input/output.

## **2. File I/O**

A file represents a sequence of bytes, regardless of it being a text file or a binary file. C programming language provides access on high level functions as well as low level (OS level) calls to handle file on your storage devices. We'll go through the important calls for file management.

### **2.1 Opening File**

You can use the `fopen()` function to create a new file or to open an existing file. This call will initialize an object of the type **FILE**, which contains all the information necessary to control the stream. The prototype is as follows:

```C
FILE *fopen(const char * filename, const char * mode); 
```

Here, filename is a string literal, which represents the path to your input file. And mode is an access mode and can have one of the following values:

| ***Mode***   | ***Description*** |
| :--:         | :--         |
| `r`          | Opens an existing text file for reading purpose. |
| `w`          | Opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file. |
| `a`          | Opens a text file for writing in appending mode. If it does not exist, then a new file is created. Here your program will start appending content in the existing file content. |
| `r+`         | Opens a text file for both reading and writing. |
| `w+`         | Opens a text file for both reading and writing. It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist. |
| `a+`         | Opens a text file for both reading and writing. It creates the file if it does not exist. The reading will start from the beginning but writing can only be appended. |

In case you want to handle a binary file, you need to insert character `'b'` after your access mode, ie,`"rb"`, `"a+b"`.

### **2.2 Closing a File**

To close a file, use the `fclose()` function. The `fclose()` function returns zero on success, or EOF if there is an error in closing the file. This function flushes any data still pending in the buffer to the file, closes the file, and releases any memory used for the file. The EOF is a constant defined in the header file `<stdio.h>`.

```C
int fclose(FILE *fp); 
```

### **2.3 Writing a File**

To write data to an output file, we use `fputs()` function, which writes the character value of the argument c to the output stream referenced by *fp*. It returns the written character written on success otherwise EOF if there is an error.

```C
int fputc(int c, FILE *fp); 
int fputs(const char *s, FILE *fp); 
```

The function `fputs()` writes the string s to the output stream referenced by *fp*. It returns a non-negative value on success, otherwise EOF is returned in case of any error.

The program below will illustrate how-to write data to a file.

```C
#include <stdio.h> 

int main(){ 
    FILE *fp;

    fp = fopen("C:\\output.txt", "w+");
    fputs("Faculty of Information Technology\n", fp);
    fputs("Ton Duc Thang University", fp);
    fclose(fp);

    return 0;
}
```

### **2.4 Reading a File**

To read a single character from a file, we use `fgets()` function, which reads a character from the input file referenced by *fp*. The return value is the character read, or in case of any error, it returns EOF.

```C
int fgetc(FILE *fp); 
int *fgets(char *buf, int n, FILE *fp); 
```

The functions `fgets()` reads up to *n - 1* characters from the input stream referenced by *fp*. It copies the read string into the buffer *buf*, appending a null character to terminate the string.

The program below will illustrate how-to read string data from a file.

```C
#include <stdio.h>
int main(){ 
    FILE *fp; 
    char buff[255]; 

    fp = fopen("C:\\input.txt", "r");

    fgets(buff, 255, (FILE*)fp); 
    printf("%s", buff); 

    fgets(buff, 255, (FILE*)fp); 
    printf("%s", buff); 

    fclose(fp); 

    return 0; 
}
```

## **3. Exercises**

1. Read the input data `(input01.txt)` contains 20 integer numbers, then write to new file the sum of them.
2. Read the input data `(input02.txt)` contains 5 strings, then write to new file the length of each string.
3. Write a program to illustrate a search program, the program's scenario is as follows:

    - Print to the console: "`enter a filename:`".
    - Read a string from the console for the filename.
    - Print a menu of the algorithms you implemented, having each represented by a letter or number.
    - Print to the console: "`choose one of these search algorithms:`".
    - Read a letter or number indicating the algorithm.
    - Print to the console: "`enter a value to search for:`".
    - Read an integer from the console as your target value, then print the position or print
    "`not found`".
