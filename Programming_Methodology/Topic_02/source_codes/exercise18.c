#include<stdio.h>
#include<math.h>

int main(){
    // Write a C program to convert Decimal to Binary number system.

    /*
    Decimal number is a number expressed in the base 10 numeral system. Decimal number's digits
        have 10 symbols: 0,1,2,3,4,5,6,7,8,9. Each digit of a decimal number counts a power of 10.
    Symbol ^ is power expression.
    Decimal number example: 653 = 6×10^2 + 5×10^1 + 3×10^1
    
    Binary number is a number expressed in the base 2 numeral system. Binary number's digits have 2 
        symbols: zero (0) and one (1). Each digit of a binary number counts a power of 2.

    Binary number example:
    1101 = 1×2^3 + 1×2^2 + 0×2^1 + 1×2^0 = 13(decimal)

    How to convert decimal to binary? We use "Divide by 2" algorithm

    Conversion steps:
        1. Divide the number by 2.
        2. Get the integer quotient for the next iteration.
        3. Get the remainder for the binary digit.
        4. Repeat the steps until the quotient is equal to 0.
    
    | Division by 2 | Quotient | Remainder | Bit # |
    |:-------------:|:--------:|:---------:|:-----:|
    |          13/2 |        6 |         1 |     0 |
    |           6/2 |        3 |         0 |     1 |
    |           3/2 |        1 |         1 |     2 |
    |           1/2 |        0 |         1 |     3 |
    The remainder when inverted is the binary value of the number
    13(decimal) = 1101(binary)

    The idea solve problem:
    
    | Division by 2 | Quotient | Remainder | Bit # | Binary                               |
    |:-------------:|:--------:|:---------:|:-----:| :----------------------------------: |
    |          13/2 |        6 |         1 |     0 | 1 * 10^0 = 1                         |
    |           6/2 |        3 |         0 |     1 | 1 * 10^0 + 0 * 10^1 = 01             |
    |           3/2 |        1 |         1 |     2 | 1 * 10^0 + 0 * 10^1 + 1 * 10^2 = 101 |
    |           1/2 |        0 |         1 |     3 |     ...                       = 1101 | 
    */

    int decimal_number, quotient, remainder, index = 0, binary = 0;

    do{
        printf("Entering the number: ");
        scanf("%d", &decimal_number);
        if(decimal_number <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(decimal_number < 0);

    quotient = decimal_number;
    // Repeat until the quotient is equal to 0
    while(quotient > 0){
        remainder = quotient % 2;
        binary += remainder * pow(10, index);
        index++;
        quotient /= 2;
    }

    printf("%d (decimal) = %d (binary)", decimal_number, binary);

    return 0;
}