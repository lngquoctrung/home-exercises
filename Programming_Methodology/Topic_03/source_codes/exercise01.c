#include<stdio.h>

// Decleration function
int isEven(int);
int sumOfEvenNumbers(int);

int main(){
    // Write a C function to print sum of all even numbers between 1 to n. Validating the \
    input, in case the input isn't correct, prompt user to enter it again.

    int n;
    
    // Entering the input and validating the input 
    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        // Checking the number whether is valid or not
        if(n < 0){
            printf("The number must be greater than 0\n");
        }
    }
    while(n < 0);

    // Calling function
    printf("Result = %d\n", sumOfEvenNumbers(n));

    return 0;
}

// Function definition
int isEven(int number){
    if(number%2 != 0) return 0;
    return 1;
}

// Function calculates the sum of all even numbers from 1 to n
int sumOfEvenNumbers(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        // Calling function check the number whether is even or not
        if(isEven(i)) sum+=i;
    }
    return sum;
}