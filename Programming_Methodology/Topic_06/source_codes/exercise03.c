#include<stdio.h>
#include<math.h>

int exponential_function_base2(int n);

int main(){
    // Define a recursive function to compute 2^n.
    int number;

    // Enter the exponent
    do{
        printf("Enter the exponent: ");
        scanf("%d", &number);
    }
    while(number < 0);

    // Display result
    printf("2^%d = %d", number, exponential_function_base2(number));

    return 0;
}

int exponential_function_base2(int n){
    if(n == 1) return 2; // Base case
    return 2 * exponential_function_base2(n - 1);
}