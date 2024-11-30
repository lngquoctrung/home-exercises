#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

int main(){
    // Read the input data (input02.txt) contains 5 strings, then write to new file the length of each string.
    char buffer[MAX_LENGTH];
    FILE *read_file, *write_file;

    // Reading and writing content of input file
    read_file = fopen("../input_data/input02.txt", "r");
    write_file = fopen("../output_files/output02.txt", "w");

    while(fgets(buffer, MAX_LENGTH, read_file) != NULL){
        buffer[strcspn(buffer, "\n") - 1] = 0; // Removing newline character
        fprintf(write_file, "Length of \"%s\" = %d\n", buffer, strlen(buffer));
    }
    
    //Closing files
    fclose(read_file);
    fclose(write_file);
    return 0;
}