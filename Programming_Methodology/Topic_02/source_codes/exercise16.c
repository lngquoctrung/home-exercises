#include<stdio.h>
#include<math.h>

int main(){

    // Write a C program to print all Armstrong numbers between \
    1 to n by using three loop structures. Validating the input, \
    in case the input isn't correct, prompt user to enter it again

    int n, temp_number, num_of_digits, armstrong_number, last_digit;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n <= 0);

    // for loop
    printf("For loop: ");
    // The loop from 1 to n
    for(int i = 1; i <= n; i++){
        temp_number = i;
        num_of_digits = 0;
        armstrong_number = 0;
        // Counting the number of digits of the number
        while (temp_number != 0){
            num_of_digits++;
            temp_number /= 10;
        }  

        // Calculating the sum of cubes of its digits
        temp_number = i;
        while (temp_number != 0){
            last_digit = temp_number % 10;
            armstrong_number += pow(last_digit, num_of_digits);
            temp_number /= 10;
        }
        
        // Checking the number whether is Armstrong number or not
        if(armstrong_number == i) printf("%d, ", i);
    }

    // while loop
    printf("\nWhile loop: ");
    int i = 1;
    while(i <= n){
        temp_number = i;
        num_of_digits = 0;
        armstrong_number = 0;
        // Counting the number of digits of the number
        while(temp_number != 0){
            num_of_digits++;
            temp_number /= 10;
        }  

        // Calculating the sum of cubes of its digits
        temp_number = i;
        while (temp_number != 0){
            last_digit = temp_number % 10;
            armstrong_number += pow(last_digit, num_of_digits);
            temp_number /= 10;
        }
        
        // Checking the number whether is Armstrong number or not
        if(armstrong_number == i) printf("%d, ", i);
        i++;
    }

    // do-while loop
    printf("\nDo-while loop: ");
    i = 1;
    do{
        temp_number = i;
        num_of_digits = 0;
        armstrong_number = 0;
        // Counting the number of digits of the number
        while (temp_number != 0){
            num_of_digits++;
            temp_number /= 10;
        }  

        // Calculating the sum of cubes of its digits
        temp_number = i;
        while (temp_number != 0){
            last_digit = temp_number % 10;
            armstrong_number += pow(last_digit, num_of_digits);
            temp_number /= 10;
        }
        
        // Checking the number whether is Armstrong number or not
        if(armstrong_number == i) printf("%d, ", i);
        i++;
    }
    while(i <= n);
    return 0;
}