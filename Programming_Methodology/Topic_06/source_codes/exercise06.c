#include<stdio.h>
#include<math.h>

// =====Support function=====
int factorial(int n);

// =====Main function=====
int expression_1(int n);
float expression_2(int n);
int expression_3(int n);
float expression_4(int n);
int expression_5(int n);

int main(){
    // Define a recursive function to compute x^n.
    int number;

    // Enter x and exponent values
    do{
        printf("Enter the number: ");
        scanf("%d", &number);
    }
    while(number < 0);

    // Display result
    printf("Result of expression 1 = %.d\n", expression_1(number));
    printf("Result of expression 2 = %.3f\n", expression_2(number));
    printf("Result of expression 3 = %d\n", expression_3(number));
    printf("Result of expression 4 = %.3f\n", expression_4(number));
    printf("Result of expression 5 = %d", expression_5(number));

    return 0;
}

// =====Support function=====
int factorial(int n){
    return n == 0 ? 1 : n * factorial(n - 1);
}

// =====Main functions=====
int expression_1(int n){
    if(n == 1) return 3; // Base case
    return (2 * n + 1) + expression_1(n - 1);
}

float expression_2(int n){
    if(n == 1) return 0.5f; // Base case
    return n/2.f + expression_2(n - 1);
}

int expression_3(int n){
    if(n == 1) return factorial(n); // Base case
    return factorial(n) + expression_3(n - 1);
}

float expression_4(int n){
    if(n == 1) return 1.f; // Base case
    return sqrt(n) + expression_4(n - 1);
}

int expression_5(int n){
    if(n == 1) return factorial(n); // Base case
    return factorial(n) * expression_5(n - 1);
}