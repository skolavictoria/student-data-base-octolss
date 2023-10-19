#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    struct Student {
        char name[20];
        char surname[20];
        int age;
        int grade;
    };
    int count = 0;
    struct Student students[30] = {};
    char answer1;
    
    do {
        printf("Enter the name of a student: ");
        fgets(students[count].name, sizeof(students[count].name), stdin);
        printf("Enter the surname of a student: ");
        fgets(students[count].surname, sizeof(students[count].surname), stdin);
        printf("Enter the age of a student: ");
        scanf("%d", &students[count].age);
        printf("Enter the grade of a student: ");
        scanf("%d", &students[count].grade);
        count++;
        
        printf("Do you want to add a student to the database? [Y/N]: ");
        scanf(" %c", &answer1);
        getchar(); 
    } while (answer1 != 'N' && answer1 != 'n');

    FILE *fp;
    fp = fopen("students.bin", "ab+");
    
    int i;
    int l = count; 
    for (i = 0; i < l; i++) {
        fprintf(fp, "Name: %s\n", students[i].name);
        fprintf(fp, "Surname: %s\n", students[i].surname);
        fprintf(fp, "Age: %d\n", students[i].age);
        fprintf(fp, "Grade: %d\n", students[i].grade);
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    
    return 0;
}