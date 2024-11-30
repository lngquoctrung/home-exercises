#include<stdio.h>

// Declare functions
// === Support Function ===
int factorial(int n);
// === Main Functions ===
int expression_1(int n);
int expression_2(int n);
float expression_3(int n);

int main(){
    // Write a function to calculate the value of the following expressions:

    // Declare the number
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    // Print result of 5 expressions
    printf("Result of expression 1 = %d\n", expression_1(n));
    printf("Result of expression 2 = %d\n", expression_2(n));
    printf("Result of expression 3 = %.3f\n", expression_3(n));
    return 0;
}

// Define function
// === Support Function ===
int factorial(int n){
    // Function use to calculate factorial of a number
    int product = 1;
    for(int i = 1; i <= n; i++){
        product *= i;
    }
    return product;
}
// === Main Functions ===
int expression_1(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (2*i + 1);
    }
    return sum;
}

int expression_2(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (factorial(i) + 1);
    }
    return sum;
}

float expression_3(int n){
    float sum = 0.f;
    for(int i = 1; i <= n; i++){
        sum += (2.f * i + 1.f) / i;
    }
    return sum;
}