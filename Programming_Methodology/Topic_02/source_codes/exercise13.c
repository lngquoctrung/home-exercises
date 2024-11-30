#include<stdio.h>
#include<math.h>

int main(){

    // Write a C program to check whether a nunber is Armstrong number or not.

    /*
    Armstrong number is a number that is equal to the sum of cubes of its digits. 
    For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
    153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27
    */

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    // Count the number of digits
    int copy_number = number, num_of_digits = 0;
    while(copy_number > 0){
        num_of_digits++;
        copy_number /= 10;
    }

    // Calculating the sum of cubes of its digits
    int sum_of_cubes = 0, last_digit;
    copy_number = number;
    while(copy_number > 0){
        last_digit = copy_number % 10;
        sum_of_cubes += pow(last_digit, num_of_digits);
        copy_number /= 10;
    }

    // Check the sum is whether equal original number or not
    if(sum_of_cubes == number) printf("%d is Armstrong number", number);
    else printf("%d not is Armstrong number", number);

    return 0;
}