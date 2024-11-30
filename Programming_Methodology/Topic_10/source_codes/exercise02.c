#include<stdio.h>
#include<math.h>
#define PI 3.14

float area_of_circle(float circumference);

int main(){
    // Write a program that allows the user to enter the circumference of a circle, calculates and returns the area of ​​that circle
    float circumference;
    printf("Enter the circumference value of circle: ");
    scanf("%f", &circumference);

    printf("The area of circle = %f", area_of_circle(circumference));

    return 0;
}

float area_of_circle(float circumference){
    // Getting radius of circle
    float r = circumference / (2 * PI);
    return PI * pow(r, 2);
}
