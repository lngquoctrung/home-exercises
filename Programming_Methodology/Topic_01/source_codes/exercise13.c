#include<stdio.h>

int main(){
    /*
    Write a C program to input marks of five subjects Physics, \
    Chemistry, Biology, Mathematics and Computer. Calculate \
    percentage and grade according to following:
        Percentage > 90%: Grade A
        Percentage > 80%: Grade B
        Percentage > 70%: Grade C
        Percentage > 60%: Grade D
        Percentage > 40%: Grade E
        Percentage < 40%: Grade F
    */

   float physics_mark, chemistry_mark, biology_mark, mathematic_mark, computer_mark, average_mark;
   int percentage;

    // Physics mark
    printf("Entering the Physics mark: ");
    scanf("%f", &physics_mark);
    // Chemistry mark
    printf("Entering the Chemistry mark: ");
    scanf("%f", &chemistry_mark);
    // Biology mark
    printf("Entering the Biology mark: ");
    scanf("%f", &biology_mark);
    // Mathematics mark
    printf("Entering the Mathematics mark: ");
    scanf("%f", &mathematic_mark);
    // Computer mark
    printf("Entering the Computer mark: ");
    scanf("%f", &computer_mark);
   
    // Calculating the percentage

    average_mark = (physics_mark + chemistry_mark + biology_mark + mathematic_mark + computer_mark) / 5.;

    percentage = (int)(average_mark * 100.) / 10.;

    printf("Percentage: %d%\n", percentage);
    if(percentage > 90){
        printf("Grade A");
    }
    else if(percentage > 80){
        printf("Grade B");
    }
    else if(percentage > 70){
        printf("Grade C");
    }
    else if(percentage > 60){
        printf("Grade D");
    }
    else if(percentage > 40){
        printf("Grade E");
    }
    else{
        printf("Grade F");
    }
    return 0;
}