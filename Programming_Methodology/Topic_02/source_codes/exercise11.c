#include<stdio.h>
#include<math.h>

int main(){

    // Wrie a C program to enter any number and check whether the number is palindrome or not.

    /*
    A palindromic number (also known as a numeral palindrome or a numeric palindrome) is a 
    number (such as 16461) that remains the same when its digits are reversed.

    Originnal number: 123321 = Reversed number: 123321
    => This is palidrome number
    */
    int original_number, reversed_number = 0;

    printf("Entering the original number: ");
    scanf("%d", &original_number);

    // Count the number of digits of original number
    int number = original_number, num_of_digits = 0;
    while(number > 0){
        num_of_digits += 1;
        number /= 10;
    }


    // Reversing the original number
    int last_digit;
    number = original_number;
    while(num_of_digits != 0){
        last_digit = number % 10;
        reversed_number += last_digit * pow(10, num_of_digits - 1);
        number /= 10;
        num_of_digits--;
    }
    // We can use loop function

    if(original_number == reversed_number){
        printf("%d is palindrome number, with reversed number is %d", original_number, reversed_number);
    }
    else{
        printf("%d is not palindrome number, with reversed number is %d", original_number, reversed_number);
    }
    return 0;
}