#include<stdio.h>

int main(){
    // Write a C program prompting user to input two integer \
    numbers, then compute and print the results of addition, \
    subtraction, multiplication, division, and remainder.

    // Hint: Using `scanf` function to enter input from the \
    terminal and `printf` to display the output on terminal. \
    Defining two variables to store values of two numbers.

    // Defining two variables
    int the_first_number;
    int the_second_number; 
    // or int the_first_number, the_second_number;

    printf("The first number: ");
    // The scanf function will write the value input by user into the integer variable the_first_number
    scanf("%d", &the_first_number);
    
    printf("The second number: ");
    scanf("%d", &the_second_number);

    // Addition
    printf("%d + %d = %d\n", the_first_number, the_second_number, the_first_number + the_second_number);

    // Subtraction
    printf("%d - %d = %d\n", the_first_number, the_second_number, the_first_number - the_second_number);

    //Multiplication
    printf("%d * %d = %d\n", the_first_number, the_second_number, the_first_number * the_second_number);

    // Division and remainder
    // With the division and remainder problem, we must use if-else statement to check whether the second number is different 0 or not.
    if(the_second_number != 0){
        // Division
        printf("%d / %d = %d\n", the_first_number, the_second_number, the_first_number / the_second_number);

        // Remainder
        printf("%d %% %d = %d\n", the_first_number, the_second_number, the_first_number % the_second_number);
    }
    else{
        printf("Can not divide by 0");
    }
    return 0;
}

// Note: I will put the function name into `the function name`