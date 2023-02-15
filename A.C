#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct student {
    char roll_number[12];
    char name[50];
    int marks_dsma;
    int marks_cp;
    int marks_dld;
} Student;

int main() {
    FILE *marks_file;
    FILE *result_file;

    marks_file = fopen("S20220010144_mark.txt", "w+");
    if (marks_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Student student_info, read_student_info;
    char grade;

    printf("Name: ");
    scanf("%s", student_info.name);

    printf("Roll Number: ");
    scanf("%s", student_info.roll_number);

    printf("Marks of DSMA (out of 100): ");
    scanf("%d", &student_info.marks_dsma);

    printf("Marks of CP (out of 100): ");
    scanf("%d", &student_info.marks_cp);

    printf("Marks of DLD (out of 100): ");
    scanf("%d", &student_info.marks_dld);

    fwrite(&student_info, sizeof(Student), 1, marks_file);

    rewind(marks_file);

    fread(&read_student_info, sizeof(Student), 1, marks_file);

    int total_marks = read_student_info.marks_dsma + read_student_info.marks_cp + read_student_info.marks_dld;
    int average_marks = total_marks / 3;

    switch (average_marks / 10) {
        case 10:
        case 9:
            grade = 'O';
            break;
        case 8:
        case 7:
            grade = 'A';
            break;
        case 6:
        case 5:
            grade = 'B';
            break;
        case 4:
            grade = 'C';
            break;
        case 3:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }

    result_file = fopen("S20220010144_result.txt", "w");
    if (result_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(result_file, "Total marks of three subjects = %d, and the grade is %c\n", total_marks, grade);

    fclose(marks_file);
    fclose(result_file);

    return 0;
}
