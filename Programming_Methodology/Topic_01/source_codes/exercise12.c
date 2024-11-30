#include<stdio.h>

int main(){
    // Write a C program to input angles of a triangle and \
    check whether triangle is valid or not.

    // Hint: The valid condition makes a triangle from three \
    angles, which is the sum of three angles must be equal 180 \
    degrees

    int first_angle, second_angle, third_angle;

    printf("Entering the first angle of the triangle: ");
    scanf("%d", &first_angle);
    printf("Entering the second angle of the triangle: ");
    scanf("%d", &second_angle);
    printf("Entering the third angle of the triangle: ");
    scanf("%d", &third_angle);

    // The sum of three angles must be equal 180 degrees
    if(first_angle + second_angle + third_angle == 180){
        printf("The triangle is valid");
    }
    else{
        printf("The triangle is invalid");
    }

    return 0;
}