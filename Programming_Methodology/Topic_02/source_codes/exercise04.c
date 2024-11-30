#include<stdio.h>

int main(){
    // Write a C program to enter any number and calculate sum of all \
    natural numbers between 1 to n using three loop structures. Validating \
    the input, in case the input isn't correct, prompt user to enter it again.

    /*
    Three loop structures:
        + for loop: 
            for(start_index; condition_breaks_loop; next_index){
                // code
            }
            Example:
            for(int i=0; i < 5; i++){
                // code
            }
        + while loop:
            while(condition_breaks_loop){
                // code
            }
            Example:
            int i = 0;
            while(i < 5){
                // code
                i++;
            }
        + do while loop:
            do{
                // code
            }
            while(contion_breaks_loop);
            Example:
            int i = 0;
            do{
                // code
                i++;
            }
            while(i < 5);
    */
    int n, sum_of_for = 0, sum_of_while = 0, sum_of_do_while = 0;
    
    // Entering the input and validating the input 
    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        // Checking the number whether is valid or not
        if(n < 0){
            printf("The number must be greater than 0\n");
        }
    }
    while(n < 0);

    // for loop
    for(int i = 1; i <= n; i++){
        sum_of_for += i;
    }
    printf("Result of for loop = %d\n", sum_of_for);

    // while loop
    int i = 1;
    while(i <= n){
        sum_of_while += i;
        i++;
    }
    printf("Result of while loop = %d\n", sum_of_while);

    // do while loop
    i = 1;
    do{
        sum_of_do_while += i;
        i++;
    }
    while(i <= n);
    printf("Result of do while loop = %d", sum_of_do_while);

    return 0;
}