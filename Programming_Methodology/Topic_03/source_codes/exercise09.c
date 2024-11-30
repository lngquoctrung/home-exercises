#include<stdio.h>
#include<math.h>

int countNumOfDigits(int);
int swapFirstAndLastDigits(int);

int main(){

    //  Write a C function to swap first and last digits of any number

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    /*
    Idea: We have a number 5768 
    Step 1: Count the number of digits -> 4 => countNumOfDigits function
    Step 2: Get first and last digits; remaining number -> 5 and 8; 76
    Step 3: Swapping two digits uses pow function -> 8 * 10 ^ (4 - 1) + 76 * 10 + 5 => swapFirstAndLastDigits function
    */

    // Result
    printf("Original number: %d -> Swapped number: %d", number, swapFirstAndLastDigits(number));

    return 0;
}
// Counting the number of digits
int countNumOfDigits(int number){
    int count = 0;
    while(number > 0){
        count += 1;
        number /= 10; 
    }
    return count;
}

// Swapping first and last digits
int swapFirstAndLastDigits(int number){
    // Counting the number of digits
    int num_of_digits = countNumOfDigits(number), swapped_number;
    // Getting first, last digits and remaining
    int first_digit, last_digit, remaining_digits;
    first_digit = number / (int)pow(10, num_of_digits-1);
    last_digit = number % 10;
    remaining_digits = (number % (int)pow(10, num_of_digits-1)) / 10;

    // Swapping first and last digits
    swapped_number = last_digit * pow(10, num_of_digits-1) + remaining_digits * 10 + first_digit;
    return swapped_number;
}