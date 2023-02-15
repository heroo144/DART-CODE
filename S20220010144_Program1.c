#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct studentig {
    char roll[12];
    char name[50];
    int marks1;
    int marks2;
    int marks3;
} stuD;

int main() {
    FILE *fptr;
    FILE *cptr;
    fptr = fopen("S20220010144_mark.txt", "w+");

    stuD s, *t=&s;
    stuD k,*p=&k;

    char grade;

    printf("Name: ");
    scanf("%s", s.name);

    printf("Roll: ");
    scanf("%s", s.roll);
    printf("Marks of DSMA(out of 100): ");
    scanf("%d", &s.marks1);
    printf("Marks of CP(out of 100): ");
    scanf("%d", &s.marks2);
    printf("Marks of DLD(out of 100): ");
    scanf("%d", &s.marks3);

    fwrite(t, sizeof(stuD), 1, fptr);

    rewind(fptr);

    fread(p, sizeof(stuD), 1, fptr);

    int mark = (p->marks1 + p->marks2 + p->marks3);
    int avg = mark / 3;

    switch (avg / 10) {
        case 10:
        case 9:
            grade = 'O';
            break;
        case 8:
        case 7:
            grade = 'E';
            break;
        case 6:
            grade = 'A';
            break;
        case 5:
            grade = 'B';
            break;
        case 4:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }

    cptr = fopen("S20220010144_result.txt", "w");
    fprintf(cptr, "Total marks of three subjects: %d \nAverage: %d \nGrade: %c \n", mark, avg, grade);

    fclose(fptr);
    fclose(cptr);

    return 0;
}
