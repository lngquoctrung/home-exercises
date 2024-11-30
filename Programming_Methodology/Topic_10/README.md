# **TOPIC 10 - REVIEW**

## **Exercises**

1. In the Oxy coordinate system, given two points $A$ and $B$ with real coordinates. Calculate the distance between two points $A$ and $B$, knowing that, $d = \sqrt{(x_{A} - x_{B})^{2}+(y_{A} - y_{B})^{2}}$.
2. Write a program that allows the user to enter the circumference of a circle, calculates and returns the area of ​​that circle.
3. Write a program that allows the user to enter date, month, year information, and then checks whether the information is valid or not.
4. Write a function that takes a string as a parameter and checks if the string is a palindrome. If so, return `1`, otherwise return `0`.
5. Write a program that uses recursion to pass in a positive integer (no checking required), then convert the passed number to binary.
6. Write a SinhVien struct containing the following information: Student ID, Full name, Programming Method score, Linear Algebra score, Math score for computer science, Cumulative average score, Ranking (excellent, good, average, poor).
    - Find students through student ID.
    - Calculate Cumulative average score for each student.
    - Calculate ranking value for each student. (Note: represent type in char type)
    - Find student with lowest average score.
    - Count how many students have *B* score or higher.
7. Write a recursive function to calculate the factorial of a non-negative number `n`. Given the definition of factorial according to the following formula:

    $$ n! =
    \begin{cases}
    1, & x \le 1\\
    n \times(n-1)!, & n \ge 1
    \end{cases}
    $$

8. Write a recursive function according to the following formula:

    $$
    f(x)=
    \begin{cases}
    1, & x=0\\
    2, & x=1\\
    2f(x-1)+3f(x-2), & x \ge 1
    \end{cases}
    $$

9. Write a recursive function according to the following formula:

    $$
    \begin{cases}
    3, & x=0\\
    5, & x=1\\
    f(x-1)+2f(x-2), & x\ge 1
    \end{cases}
    $$

10. Write a recursive function according to the following formula:

    $$
    \begin{cases}
    4, & x=0\\
    7, & x=1\\
    4f(x-1)-f(x-2), & x\ge 1
    \end{cases}
    $$

11. Write a function with two parameters, an array of positive integers and the number of elements `n`. The function returns the sum of the prime numbers in the array.
12. Write a function that implements the selection sort and bubble sort algorithms.
13. Write a program that inputs the number of seconds, which is an integer `n`. Convert this number of seconds into hours, minutes, seconds and print the result on the screen.
14. Write a function with the following declaration `int countDuplicate(int a[], int n, int k)`. The source code implementation is required to count and return the number of occurrences of the value `k` in the array `a[]`.
15. Write a function to search for a value `k` in an array of integers, declaring the function as follows: `int search(int a[], int n, int k)`. The result returned is the position of the value `k` in the array.
16. Write a function to calculate the sum of even numbers in an integer array.
17. Write a function to calculate the sum of odd numbers in an integer array.
18. Write a function to find the largest number in an integer array.
19. Write a function to find the smallest number in an integer array.
20. Write a function to calculate the value of the following expressions:

    - $$\sum_{i=1}^{n}(2i+1)$$
    - $$\sum_{i=1}^{n}(i!+1)$$
    - $$\sum_{i=1}^{n}\frac{2i+1}{i}$$
