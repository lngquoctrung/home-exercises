# **TOPIC 02 - CONDITIONAL AND LOOP STRUCTURES**

## **1. Introduction**

In previvous [topic](../Topic_01/), we learned about the fundamental knowledges in C programming language such as datatypes, variables, conditional structures etc. In this topic, we will continue with another conditional structure, and study loop structure.

## **2. Conditional Structures**

In [Topic 01](../Topic_01/), we presented a basic form of conditional structure, called if-else. Now, we study a new approach, when we have many cases in making decision with one condition (may contain more than one Boolean expression). Instead of defining many if-else statements, we can use `switch` structure, as follows:

```C
switch(expression){
    case const-expr-1: statements
    case const-expr-2: statements
    case const-expr-3: statements
    default: statements
}
```

Each case is labeled by one or more integer-valued constants or constant expressions. If a case matches the expression value, execution starts at that case. All case expressions must be different. The case labeled `default` is executed if none of the other cases are satisfied. A `default` is optional; if it isn't there and if none of the cases match, no action at all takes place. Cases and the default clause can occur in any order.

```C
// switch.c
#include<stdio.h>

int main(){
    int choice = 0;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 0: case 1:
            printf("Coke\n");
            break;
        case 2:
            printf("Coffee\n");
            break;
        case 3:
            printf("Tea\n");
            break;
        default:
            printf("Water\n");
            break;
    }
}
```

The sample above program illustrates the switch structure. It contains 5 cases, and case `0` and `1` have the same result, the `default` case handles the choices which are out of pre-defined cases. The most important things that you should motice is each case (inc. default) has to have `break`; unless you define `break`, the program will continue process other cases until reaching the last one. For example. if the above program doesn't have break statement, when `choice` is 0, it will print out all cases.

### **3. Loop Structures**

Often in computer programming, it is necessary to perform a certain action a certain number of times or until a certain condition is met. The constructs that enable computers to perform certain repetitive tasks are called loops.

#### **3.1. `while` loop**

A `while` loop is the most basic type of loop structure. It will run until the condition is non-zero (true). Before executing the statements inside while body, it will check whether the condition is true, then it executes the statements. You should note that in case the condition of loop never bebomes false. then we will fall into infinite loop. Let's the below sample program.

```C
// while.c
#include<stdio.h>

int main(){
    int i = 0;

    while(i < 10){
        printf("No. %d\n", i);

        i = i + 1; // Update the condition
    }
}
```

The flow of all loops can also be controlled by `break` and `continue` statements. A `break` statement will immediately exit the enclosing loop. A `continue` statement will skip the remainder of the block and start at the controlling conditional statement again.

#### **3.2 `for` loop**

The structure of loop is as the below program, the initialization statement is executed only one, before the first evaluation of test condition. Typically, it is used to assign an initial value to some, variable, although this is not strictly necessary. The test expression is evaluted each time before the code in the for loop executes. After each iteration of the loop, the increment statement is executed. This often is used to increment the loop index for the loop, the variable initialized in the initialization expression and tested in the test expression.

```C
// for.c
#include<stdio.h>

int main(){
    int i = 0;

    for(i = 0; i < 10; i++){
        printf("No. %d\n", i);
    }
}
```

#### **3.3 `do-while` loop**

A `do-while` loop is a post-check while loop, which means that it checks the condition after each run. As a result, even if the condition is zero (false), it will run at least once.

```C
// dowhile.c
#include<stdio.h>

int main(){
    int i = 1;

    do{
        printf("No. %d\n", i);
    }
    while(i < 1);
}
```

A do-while loop sometimes uses in validating a user's input. For example, if you want to validate whether an input is correct or not, you can take advantage of do-while loop, as following program.

```C
#include<stdio.h>

int main(){
    int input, i = 0;

    do{
        printf("Input = ");
        scanf("%d", &input);

        // Control number of loops
        i++;
    }
    while(i < 0);
    printf("Input is a positive integer number!");
}
```

## **4. Exercises**

1. Write a C program to print sum of all even numbers between 1 to n by using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
2. Write a C program to print sum of all odd numbers between 1 to n by using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
3. Write a C program to print table of any number
4. Write a C program to enter any number and calculate sum of all natural numbers between 1 to n using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
5. Write a C program to find first and last digits of any number.
6. Write a C program to calculate sum of digits of any number.
7. Write a C program to calculate product of digits of any number.
8. Write a C program to count number of digits of any number.
9. Write a C program to swap first and last digits of any number.
10. Write a C program to enter any number and print its reverse.
11. Wrie a C program to enter any number and check whether the number is palindrome or not.
12. Wrie a C program to check whether a number is Prime number or not. Validating the input, in case the input isn't correct, prompt user to enter it again.
13. Write a C program to check whether a nunber is Armstrong number or not.
14. Write a C program to check whether a number is Perfect number or not.
15. Write a C program to print all Prime numbers between 1 to n by using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
16. Write a C program to print all Armstrong numbers between 1 to n by using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
17. Write a C program to print all Perfect numbers between 1 to n by using three loop structures. Validating the input, in case the input isn't correct, prompt user to enter it again.
18. Write a C program to convert Decimal to Binary number system.
19. Write a C program to compute the Factorial of n. Validating the input, in case the input isn't correct, prompt user to enter it again
$$n! = 1 * 2 * 3 * ... * n \quad (n \geq 0)$$
