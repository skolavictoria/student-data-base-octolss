#include <stdio.h>
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
        fgets(students[count].name, sizeof(students[count].name), stdin);//only worked with fgets(scanf didnt work)
        students[count].name[strcspn(students[count].name, "\n")] = 0;
        printf("Enter the surname of a student: ");
        fgets(students[count].surname, sizeof(students[count].surname), stdin);
        students[count].surname[strcspn(students[count].surname, "\n")] = 0;
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
    }

    fclose(fp);

    char answer[20];
    char name_surname[20];
    int age_grade;

    printf("Would you like to search the student via his name or surname? [Y/N]: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "Y") == 0) {
        printf("Enter name or surname: ");
        getchar();
        fgets(name_surname, sizeof(name_surname), stdin);
        name_surname[strcspn(name_surname, "\n")] = 0;
        for (i = 0; i < count; i++) {
            if (strcmp(students[i].name, name_surname) == 0 || strcmp(students[i].surname, name_surname) == 0) {
                printf("Name: %s\n", students[i].name);
                printf("Surname: %s\n", students[i].surname);
                printf("Age: %d\n", students[i].age);
                printf("Grade: %d\n", students[i].grade);
            }
        }
    } else if (strcmp(answer, "N") == 0) {
        printf("Enter age or grade: ");
        scanf("%d", &age_grade);
        for (i = 0; i < count; i++) {
            if (students[i].age == age_grade || students[i].grade == age_grade) {
                printf("Name: %s\n", students[i].name);
                printf("Surname: %s\n", students[i].surname);
                printf("Age: %d\n", students[i].age);
                printf("Grade: %d\n", students[i].grade);
            }
        }
    }

    return 0;
}
//different code parts were fixed by chatGPT