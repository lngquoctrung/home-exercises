#include<stdio.h>

// Declare functions
// === Support Function ===
int factorial(const int n);
// === Main Functions ===
float expression_1(const int n);
int expression_2(const int n);
float expression_3(const int n);
int expression_4(const int n);
int expression_5(const int n);
int expression_6(const int n);
float expression_7(const int n);
float expression_8(const int n);

int main(){

    // Write functions to calculate the following expressions

    // Declare the number
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    // Print result of 8 expressions
    printf("Result of expression 1 = %.3f\n", expression_1(n));
    printf("Result of expression 2 = %d\n", expression_2(n));
    printf("Result of expression 3 = %.3f\n", expression_3(n));
    printf("Result of expression 4 = %d\n", expression_4(n));
    printf("Result of expression 5 = %d\n", expression_5(n));
    printf("Result of expression 6 = %d\n", expression_6(n));
    printf("Result of expression 7 = %.3f\n", expression_7(n));
    printf("Result of expression 8 = %.3f\n", expression_8(n));
    return 0;
}

// Define function
// === Support Function ===
int factorial(const int n){
    // Function use to calculate factorial of a number
    int product = 1;
    for(int i = 1; i <= n; i++){
        product *= i;
    }
    return product;
}

// === Main Functions ===
float expression_1(const int n){
    float sum = .0f;
    for(int i = 1; i <= n; i++){
        sum += i/2.f;
    }
    return sum;
}

int expression_2(const int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (2*i + 1);
    }
    return sum;
}

float expression_3(const int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (i + 1.f)/(1 + 2.f);
    }
    return sum;
}

int expression_4(const int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (factorial(i) + 1);
    }
    return sum;
}

int expression_5(const int n){
    float product = 1.f;
    for(int i = 1; i <= n; i++){
        product *= i;
    }
    return product;
}

int expression_6(const int n){
    float product = 1.f;
    for(int i = 1; i <= n; i++){
        product *= factorial(i);
    }
    return product;
}

float expression_7(const int n){
    float product = 1.f;
    for(int i = 1; i <= n; i++){
        product *= ((2.f*i) / 3.f);
    }
    return product;
}

float expression_8(const int n){
    float product = 1.f;
    for(int i = 1; i <= n; i++){
        product *= (i - 1.f)/(i + 1.f);
    }
    return product;
}