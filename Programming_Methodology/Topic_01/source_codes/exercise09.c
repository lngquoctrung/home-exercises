#include<stdio.h>

int main(){

    // Write a C program to find maximum between three numbers.

    int first_num, second_num, third_num;

    printf("Entering the first number: ");
    scanf("%d", &first_num);
    printf("Entering the second number: ");
    scanf("%d", &second_num);
    printf("Entering the third number: ");
    scanf("%d", &third_num);

    // Finding the maximum between two numbers. After that, \
    finding maximum between result just found and third number.
    int maximum_btw_2num = first_num >= second_num ? first_num : second_num;
    int maximum_num = maximum_btw_2num >= third_num ? maximum_btw_2num : third_num;

    printf("The maximum number is %d", maximum_num);

    return 0;
}