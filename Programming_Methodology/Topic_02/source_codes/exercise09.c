#include<stdio.h>
#include<math.h>

int main(){

    //  Write a C program to swap first and last digits of any number

    int number, swapped_number;

    printf("Entering the number: ");
    scanf("%d", &number);

    /*
    Idea: We have a number 5768 
    Step 1: Count the number of digits -> 4
    Step 2: Get first and last digits; remaining number -> 5 and 8; 76
    Step 3: Swapping two digits uses pow function -> 8 * 10 ^ (4 - 1) + 76 * 10 + 5
    */

    // Counting the number of digits
    int copy_number = number, count = 0;
    while(copy_number > 0){
        count += 1;
        copy_number /= 10; 
    }

    // Get first, last digits and remaining
    int first_digit, last_digit, remaining_digits;
    first_digit = number / (int)pow(10, count-1);
    last_digit = number % 10;
    remaining_digits = (number % (int)pow(10, count-1)) / 10;

    // Swap first and last digits
    swapped_number = last_digit * pow(10, count-1) + remaining_digits * 10 + first_digit;

    // Result
    printf("Original number: %d -> Swapped number: %d", number, swapped_number);

    return 0;
}