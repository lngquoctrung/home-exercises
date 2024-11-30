#include <stdio.h>
int main() {
    // Write a program that inputs the number of seconds, which is an integer n. Convert this number of seconds into hours, minutes, seconds and print the result on the screen.
    
    int sec, h, m, s; // Declare variables for seconds, hours, minutes, and seconds
    
    // Prompt user for input seconds and store in 'sec'
    printf("Input seconds: ");
    scanf("%d", &sec);
	
    // Calculate hours, minutes, and remaining seconds
    h = (sec/3600); 
    m = (sec -(3600*h))/60;
    s = (sec -(3600*h)-(m*60));
	
    // Print the time in format H:M:S
    printf("H:M:S - %d:%d:%d\n",h,m,s);
	
    return 0;
}