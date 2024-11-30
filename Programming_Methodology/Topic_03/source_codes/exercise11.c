#include<stdio.h>
#include<math.h>

int countNumOfDigits(int);
int isPalindromeNumber(int);

int main(){

    // Write a C function to enter any number and check whether the number is palindrome or not.

    /*
    A palindromic number (also known as a numeral palindrome or a numeric palindrome) is a 
    number (such as 16461) that remains the same when its digits are reversed.

    Originnal number: 123321 = Reversed number: 123321
    => This is palidrome number
    */
    int original_number;

    printf("Entering the original number: ");
    scanf("%d", &original_number);

    if(isPalindromeNumber(original_number))
        printf("%d is palindrome number", original_number);
    else
        printf("%d is not palindrome number", original_number);

    return 0;
}

// Count the number of digits of original number
int countNumOfDigits(int number){
    int count = 0;
    while(number > 0){
        count += 1;
        number /= 10; 
    }
    return count;
}

int isPalindromeNumber(int number){
    // Reversing the original number
    int last_digit, reversed_number = 0, copied_number = number, num_of_digits = countNumOfDigits(number);
    while(num_of_digits != 0){
        last_digit = copied_number % 10;
        reversed_number += last_digit * pow(10, num_of_digits - 1);
        copied_number /= 10;
        num_of_digits--;
    }

    if(number != reversed_number) return 0;
    return 1;
}