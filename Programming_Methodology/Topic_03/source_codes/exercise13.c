#include<stdio.h>
#include<math.h>

int countNumOfDigits(int);
int isArmstrongNumber(int);

int main(){

    // Write a C function to check whether a number is Armstrong number or not.

    /*
    Armstrong number is a number that is equal to the sum of cubes of its digits. 
    For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
    153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27
    */

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    // Check the sum is whether equal original number or not
    if(isArmstrongNumber(number)) printf("%d is Armstrong number", number);
    else printf("%d not is Armstrong number", number);

    return 0;
}

// Count the number of digits
int countNumOfDigits(int number){
    int count = 0;
    while(number > 0){
        count += 1;
        number /= 10; 
    }
    return count;
}

int isArmstrongNumber(int number){
    // Calculating the sum of cubes of its digits
    int sum_of_cubes = 0, last_digit, copied_number = number, num_of_digits = countNumOfDigits(number);
    while(copied_number > 0){
        last_digit = copied_number % 10;
        sum_of_cubes += pow(last_digit, num_of_digits);
        copied_number /= 10;
    }
    if(sum_of_cubes != number) return 0;
    return 1;

}