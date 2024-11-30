#include<stdio.h>

int isPerfectNumber(int);
void printPerfectNumbers(int);

int main(){
    //  Write a C function to print all Perfect numbers between 1 to n. \
    Validating the input, in case the input isn't correct, prompt user to \
    enter it again

    int n, sum_of_proper_divisors;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n <= 0);

    printPerfectNumbers(n);

    return 0;
}

// Check the number whether is Perfect number or not.
int isPerfectNumber(int number){
    int sum_of_proper_divisors = 0;
    // Finding and adding proper divisors of the number
    for(int i = 1; i < number; i++){
        // Checking i is whether proper divisor of number or not.
        if(number % i == 0){
            sum_of_proper_divisors += i;
        }
    }
    if(number != sum_of_proper_divisors) return 0;
    return 1;
}

void printPerfectNumbers(int n){
    for(int i = 1; i <= n; i++){
        if(isPerfectNumber(i)) printf("%d, ", i);
    }
}