#include<stdio.h>

int count_num_of_digits(int n);

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
    printf("The number of digits of %d are %d", number, count_num_of_digits(number));

    return 0;
}

int count_num_of_digits(int n){
    if(n == 0) return 0; // Base case
    return 1 + count_num_of_digits(n / 10);
}