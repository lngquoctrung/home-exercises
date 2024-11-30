#include<stdio.h>

// Declare functions
// === Support Function ===
int factorial(int n);
// === Main Functions ===
float expression_1(int n);
int expression_2(int n);
int expression_3(int n);
int expression_4(int n);
float expression_5(int n);

int main(){

    // Write functions to calculate the following expressions

    // Declare the number
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    // Print result of 5 expressions
    printf("Result of expression 1 = %.3f\n", expression_1(n));
    printf("Result of expression 2 = %d\n", expression_2(n));
    printf("Result of expression 3 = %d\n", expression_3(n));
    printf("Result of expression 4 = %d\n", expression_4(n));
    printf("Result of expression 5 = %.3f", expression_5(n));
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
float expression_1(int n){
    float sum = .0f;
    for(int i = 1; i <= n; i++){
        sum += i/2.f;
    }
    return sum;
}

int expression_2(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (2*i + 1);
    }
    return sum;
}

int expression_3(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (factorial(i) + 1);
    }
    return sum;
}

int expression_4(int n){
    int product = 1;
    for(int i = 1; i <= n; i++){
        product *= factorial(i);
    }
    return product;
}

float expression_5(int n){
    float product = 1.f;
    for(int i = 1; i <= n; i++){
        product *= ((2.f*i) / 3.f);
    }
    return product;
}