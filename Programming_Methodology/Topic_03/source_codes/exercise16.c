#include<stdio.h>
#include<math.h>

int countNumOfDigits(int);
int isArmstrongNumber(int);
void printArmstrongNumbers(int);

int main(){

    // Write a C function to print all Armstrong numbers between 1 to n. \
    Validating the input, in case the input isn't correct, prompt user to \
    enter it again

    int n;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n <= 0);

    printArmstrongNumbers(n);
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

void printArmstrongNumbers(int number){
    // The loop from 1 to n
    for(int i = 1; i <= number; i++){
        if(isArmstrongNumber(i)) printf("%d, ", i);
    }
}