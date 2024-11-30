#include<stdio.h>

int main(){
    // Write a C program to convert the temperature \
    from Celsius to Fahrenheit.

    float const FAHRENHEIT = 33.8;

    float celsius_degree;
    printf("Entering Celsius degree: ");
    scanf("%f", &celsius_degree);

    printf("%.2f degress(s) Celsius -> %.2f degree(s) Fahrenheit", celsius_degree, celsius_degree * FAHRENHEIT);

    return 0;
}