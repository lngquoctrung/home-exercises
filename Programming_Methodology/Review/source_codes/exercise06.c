#include<stdio.h>

int isPrimeNumber(int);
void printPrimeNumbers(int);

int main(){

    // Write a C function to print all Prime numbers between 1 to n. Validating \
    the input, in case the input isn't correct, prompt user to enter it again

    /*
    We use a parent loop to print all number from 1 to n and \
    child loop to check the number is whether is Prime number \
    or not.
    */

    int n;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n <= 0);
    printPrimeNumbers(n);
    return 0;
}

// Function check the number whether is Prime or not
int isPrimeNumber(int number){
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}

void printPrimeNumbers(int n){
    // Parent loop to print all number from 1 to n
    for(int i = 1; i <= n; i++){
        // Child loop check the number is whether Prime number or not
        if(isPrimeNumber(i)){
            printf("%d, ", i);
        }
    }
}