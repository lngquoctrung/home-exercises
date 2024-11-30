#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 1000

typedef struct SinhVien{
    int id;
    char full_name[MAX_LENGTH];
    float programming_method_score;
    float linear_algebra_score;
    float math_score;
    float average_score;
    char ranking;

    void (*to_string)(struct SinhVien *student);
} SinhVien;
void to_string(SinhVien *student);

float get_average_score(SinhVien student);
char get_ranking(SinhVien student);
SinhVien* init_student_list(const int num_of_students);
void display_list(SinhVien *students, int num_of_students);
int linear_search(SinhVien *students, const int num_of_students, const int key);
int lowest_avg(SinhVien *students, const int num_of_students);
int count_num_of_B_higher_scores(SinhVien *students, const int num_of_students);

int main(){
    /*
    Write a SinhVien struct containing the following information: 
        Student ID, 
        Full name, 
        Programming Method score, 
        Linear Algebra score, 
        Math score for computer science, 
        Cumulative average score, 
        Ranking (excellent, good, average, poor).
    Requirements:
        - Find students through student ID.
        - Calculate Cumulative average score for each student.
        - Calculate ranking value for each student. (Note: represent type in char type)
        - Find student with lowest average score.
        - Count how many students have good academic performance or higher.
    */

    int num_of_students = 10, key;
    SinhVien *students;
    students = init_student_list(num_of_students);

    // Display student list
    display_list(students, num_of_students);

    int lowest_avg_index = lowest_avg(students, num_of_students);
    printf("\nThe student has lowest average is: \n");
    students[lowest_avg_index].to_string(&students[lowest_avg_index]);

    printf("\nThe number of students has 'B' score or higher: %d\n", count_num_of_B_higher_scores(students, num_of_students));

    printf("\nEntering the Id to search: ");
    scanf("%d", &key);

    int found_index = linear_search(students, num_of_students, key);
    found_index != -1 ? students[found_index].to_string(&students[found_index]) : printf("Not found");

    // Releasing memory
    free(students);
    return 0;
}

void to_string(SinhVien *student){
    char str[MAX_LENGTH];
    snprintf(str, MAX_LENGTH, 
             "Student{Id=%d, full_name=\"%s\", program_method_score=%.2f, linear_algebra_score=%.2f, math_score=%.2f, average_score=%.2f, ranking='%c'}", 
             student->id, 
             student->full_name, 
             student->programming_method_score, 
             student->linear_algebra_score, 
             student->math_score, 
             student->average_score, 
             student->ranking);
    puts(str);
}

float get_average_score(SinhVien student){
    return (student.programming_method_score + 
            student.linear_algebra_score + 
            student.math_score) / 3.f;
}

char get_ranking(SinhVien student){
    if(student.average_score >= 9.0) return 'A';
    else if(student.average_score >= 8.0) return 'B';
    else if(student.average_score >= 7.0) return 'C';
    else if(student.average_score >= 6.0) return 'D';
    else if(student.average_score >= 4.0) return 'E';
    else return 'F';
}

SinhVien* init_student_list(const int num_of_students){
    // Declaring first and last names to generate full names
    char *first_names[10] = {"James", "Michael", 
                            "Robert", "Thomas", 
                            "Richard", "Susan", 
                            "Elizabeth", "Jessica", 
                            "Charles", "Daniel"};
    char *last_names[10] = {"Smith", "Brown", 
                            "Miller", "Johnson", 
                            "Jones", "Davis", 
                            "Williams", "Garcia", 
                            "Martinez", "Wilson"};
    float min = 0.f, max = 10.f;
    SinhVien *students = (SinhVien*)malloc(num_of_students * sizeof(SinhVien));
    if(students == NULL){
        printf("Don't have enough memory to allocate");
        exit(1);
    }

    for(int i = 0; i < num_of_students; i++){
        students[i].id = i;
        snprintf(students[i].full_name, MAX_LENGTH, "%s %s", 
                 first_names[rand() % 10], 
                 last_names[rand() % 10]); // Combine first and last names
        students[i].programming_method_score = min + (rand() / (float)RAND_MAX) * (max - min);
        students[i].linear_algebra_score = min + (rand() / (float)RAND_MAX) * (max - min);
        students[i].math_score = min + (rand() / (float)RAND_MAX) * (max - min);
        students[i].average_score = get_average_score(students[i]);
        students[i].ranking = get_ranking(students[i]);
        students[i].to_string = to_string;
    }

    return students;
}

void display_list(SinhVien *students, int num_of_students){
    for(int i = 0; i < num_of_students; i++)
        students[i].to_string(&students[i]);
}

int linear_search(SinhVien *students, const int num_of_students, const int key){
    for(int i = 0; i < num_of_students; i++)
        if(students[i].id == key)
            return i;
    return -1;
}
int lowest_avg(SinhVien *students, const int num_of_students){
    int min_index = 0;
    for(int i = 0; i < num_of_students; i++)
        if(students[i].average_score < students[min_index].average_score)
            min_index = i;
    return min_index;
}
int count_num_of_B_higher_scores(SinhVien *students, const int num_of_students){
    int count = 0;
    for(int i = 0; i < num_of_students; i++)
        if(students[i].ranking == 'B' || students[i].ranking == 'A')
            count++;
    return count;
}
