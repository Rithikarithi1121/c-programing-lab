#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
char name[50];
int roll;
float marks;
};

void addStudent(struct Student students[], int *count) {
printf("Enter student name: ");
scanf("%s", students[*count].name);
printf("Enter roll number: ");
scanf("%d", &students[*count].roll);
printf("Enter marks: ");
scanf("%f", &students[*count].marks);
(*count)++;
}

void displayStudents(struct Student students[], int count) {
for (int i = 0; i < count; i++) {
printf("Name: %s, Roll: %d, Marks: %.2f\n", students[i].name, students[i].roll, students[i].marks);
}
}

void searchStudent(struct Student students[], int count, int roll) {
for (int i = 0; i < count; i++) {
if (students[i].roll == roll) {
printf("Name: %s, Roll: %d, Marks: %.2f\n", students[i].name, students[i].roll, students[i].marks);
return;
}
}
printf("Student not found!\n");
}

void calculateAverage(struct Student students[], int count) {
float sum = 0;
for (int i = 0; i < count; i++) {
sum += students[i].marks;
}
printf("Average marks: %.2f\n", sum / count);
}

int main() {
struct Student students[MAX_STUDENTS];
int count = 0;
int choice;
int roll;

while (1) {  
    printf("1. Add student\n");  
    printf("2. Display all students\n");  
    printf("3. Search by roll number\n");  
    printf("4. Calculate average marks\n");  
    printf("5. Exit\n");  
    printf("Enter your choice: ");  
    scanf("%d", &choice);  

    switch (choice) {  
        case 1:  
            addStudent(students, &count);  
            break;  
        case 2:  
            displayStudents(students, count);  
            break;  
        case 3:  
            printf("Enter roll number: ");  
            scanf("%d", &roll);  
            searchStudent(students, count, roll);  
            break;  
        case 4:  
            calculateAverage(students, count);  
            break;  
        case 5:  
            exit(0);  
        default:  
            printf("Invalid choice!\n");  
    }  
}  

return 0;

}
