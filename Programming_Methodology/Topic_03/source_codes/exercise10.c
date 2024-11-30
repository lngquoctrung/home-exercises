#include<stdio.h>
#include<math.h>

int countNumOfDigits(int);
void printReverseNumber(int);

int main(){

    // Write a C function to print an input number in reverse order.

    int number;
    /*
    Idea: We have a number: 9876
    Step 1: Count the number of digits
    Step 2: Splitting last number and multiplying with 10 power of the number of digits subtract 1. -> 6 * 10 ^ 3 = 6000; remaining part of the original number is 987.
    Step 3: We do step 2 again with remaining part of the original number but the number of digits will be 2 and we sum with 6000 -> 6000 + 7 * 10 ^ 2 = 6700. Each loop we subtract the number of digits with 1. We do step 2 again until the number of digit is equal 0.
    */

    printf("Entering the original number: ");
    scanf("%d", &number);

    printReverseNumber(number);

    return 0;
}

int countNumOfDigits(int number){
    int count = 0;
    while(number > 0){
        count += 1;
        number /= 10; 
    }
    return count;
}

void printReverseNumber(int original_number){
    // Reversing the original number
    int last_digit, reversed_number, copied_number = original_number, num_of_digits = countNumOfDigits(original_number);
    while(num_of_digits != 0){
        last_digit = copied_number % 10;
        reversed_number += last_digit * pow(10, num_of_digits - 1);
        copied_number /= 10;
        num_of_digits--;
    }
    printf("Original number: %d -> Reversed number: %d", original_number, reversed_number);
}