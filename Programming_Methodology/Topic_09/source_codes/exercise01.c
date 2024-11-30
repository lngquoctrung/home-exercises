#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

int main(){
    // Read the input data (input01.txt) contains 20 integer numbers, then write to new file the sum of them.
    char buffer[MAX_LENGTH], *token;
    FILE *read_file, *write_file;
    int number, sum = 0;

    // Reading content of input file
    read_file = fopen("../input_data/input01.txt", "r");
    fgets(buffer, MAX_LENGTH, read_file);

    // Plitting 20 numbers
    token = strtok(buffer, ", ");
    while (token != NULL){
        sscanf(token, "%d", &number); // Converting string to int
        sum += number;
        token = strtok(NULL, ", "); // Continuous plitting
    }
    
    // Writing content to file
    write_file = fopen("../output_files/output01.txt", "w");
    fprintf(write_file, "Sum = %d", sum);

    //Closing files
    fclose(read_file);
    fclose(write_file);
    return 0;
}