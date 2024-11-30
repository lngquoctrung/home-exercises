#include<stdio.h>

int sumOfNumbers(int);

int main(){
    // Write a C function to enter any number and calculate sum of all natural numbers between\
    1 to n. Validating the input, in case the input isn't correct, prompt user to enter it again

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
    printf("Result = %d\n", sumOfNumbers(n));

    return 0;
}

int sumOfNumbers(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum+=i;
    }
    return sum;
}