#include<stdio.h>
#include<math.h>

int main(){

    // Write a C program to enter any number and print its reverse.

    int original_number, reversed_number = 0;
    /*
    Idea: We have a number: 9876
    Step 1: Count the number of digits
    Step 2: Splitting last number and multiplying with 10 power of the number of digits subtract 1. -> 6 * 10 ^ 3 = 6000; remaining part of the original number is 987.
    Step 3: We do step 2 again with remaining part of the original number but the number of digits will be 2 and we sum with 6000 -> 6000 + 7 * 10 ^ 2 = 6700. Each loop we subtract the number of digits with 1. We do step 2 again until the number of digit is equal 0.
    */

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

    printf("Original number: %d -> Reversed number: %d", original_number, reversed_number);

    return 0;
}