#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
int* find_all(char *str, const char character);

int main(){
    // Input a string and check whether a character appears or not. If yes, return the all appearing positons.
    char str[MAX_LENGTH], character;
    int *positions, size = 0;

    input(str, "Enter the string: ");

    printf("Enter the charater: ");
    scanf("%c", &character);

    positions = find_all(str, character);
    
    // Determine size of dynamic array
    while (positions[size] != -1)
        size++;

    // Display result
    printf("Each position appear character: ");
    for(int i = 0; i < size; i++){
        printf("%d, ", positions[i]);
    }

    // Release memory
    free(positions);

    return 0;
}

void input(char str[MAX_LENGTH], const char *text){
    // Get input
    printf("%s", text);
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline when using 'fgets' function
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

// =====Main Function=====
int* find_all(char *str, const char character){
    // Count the number of positions of character that appear in string
    int counter = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == character)
            counter++;
    
    // Create dynamic array to store positions
    int *positions = (int*)malloc((counter + 1) * sizeof(int));
    int array_index = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == character){
            positions[array_index] = i;
            array_index++;
        }
    positions[counter] = -1; // Assign `not found` value to determine the size of array
    return positions;
}