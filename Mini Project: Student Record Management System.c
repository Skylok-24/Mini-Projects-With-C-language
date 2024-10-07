#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define SUBJECTS_COUNT 4

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    Date dateOfBirth;
    char address[MAX_ADDRESS_LENGTH];
    int class;
    int contact;
    float average;
    float marks[SUBJECTS_COUNT];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Date inputDate() {
    Date date;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);
    return date;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Maximum number of students reached.\n");
        return;
    }

    Student *s = &students[studentCount];

    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter First Name: ");
    scanf("%s", s->firstName);

    printf("Enter Last Name: ");
    scanf("%s", s->lastName);

    s->dateOfBirth = inputDate();

    clearInputBuffer();
    printf("Enter Address: ");
    fgets(s->address, MAX_ADDRESS_LENGTH, stdin);
    s->address[strcspn(s->address, "\n")] = 0;

    printf("Enter Class: ");
    scanf("%d", &s->class);

    printf("Enter Contact: ");
    scanf("%d", &s->contact);

    s->average = 0;
    memset(s->marks, 0, sizeof(s->marks));

    studentCount++;
    printf("Student added successfully.\n");
}

int findStudent(const char *firstName, const char *lastName) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].firstName, firstName) == 0 &&
            strcmp(students[i].lastName, lastName) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteStudent() {
    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH];
    printf("Enter First Name: ");
    scanf("%s", firstName);
    printf("Enter Last Name: ");
    scanf("%s", lastName);

    int index = findStudent(firstName, lastName);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    printf("Student deleted successfully.\n");
}

void displayStudent(const Student *s) {
    printf("ID: %d\n", s->id);
    printf("Name: %s %s\n", s->firstName, s->lastName);
    printf("Date of Birth: %d/%d/%d\n", s->dateOfBirth.day, s->dateOfBirth.month, s->dateOfBirth.year);
    printf("Address: %s\n", s->address);
    printf("Class: %d\n", s->class);
    printf("Contact: %d\n", s->contact);
    printf("Average: %.2f\n", s->average);
    printf("Marks: Physics: %.2f, Math: %.2f, Arabic: %.2f, English: %.2f\n",
           s->marks[0], s->marks[1], s->marks[2], s->marks[3]);
    printf("\n");
}

void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("Student %d:\n", i + 1);
        displayStudent(&students[i]);
    }
}

void fillMarks() {
    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH];
    printf("Enter First Name: ");
    scanf("%s", firstName);
    printf("Enter Last Name: ");
    scanf("%s", lastName);

    int index = findStudent(firstName, lastName);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    Student *s = &students[index];
    const char *subjects[] = {"Physics", "Math", "Arabic", "English"};

    float total = 0;
    for (int i = 0; i < SUBJECTS_COUNT; i++) {
        printf("Enter mark for %s: ", subjects[i]);
        scanf("%f", &s->marks[i]);
        total += s->marks[i];
    }
    s->average = total / SUBJECTS_COUNT;

    printf("Marks updated successfully.\n");
}

void displayReportCard() {
    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH];
    printf("Enter First Name: ");
    scanf("%s", firstName);
    printf("Enter Last Name: ");
    scanf("%s", lastName);

    int index = findStudent(firstName, lastName);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\n===== Report Card =====\n");
    displayStudent(&students[index]);
}

void searchStudents() {
    printf("Search by:\n");
    printf("1. First Name\n");
    printf("2. Last Name\n");
    printf("3. Address\n");
    printf("4. Average or ID or Class\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    char searchStr[MAX_NAME_LENGTH];
    float searchNum;

    switch (choice) {
        case 1:
        case 2:
        case 3:
            printf("Enter search term: ");
            scanf("%s", searchStr);
            break;
        case 4:
            printf("Enter search value: ");
            scanf("%f", &searchNum);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        bool match = false;
        switch (choice) {
            case 1:
                match = (strcmp(students[i].firstName, searchStr) == 0);
                break;
            case 2:
                match = (strcmp(students[i].lastName, searchStr) == 0);
                break;
            case 3:
                match = (strstr(students[i].address, searchStr) != NULL);
                break;
            case 4:
                match = (students[i].average == searchNum ||
                         students[i].id == (int)searchNum ||
                         students[i].class == (int)searchNum);
                break;
        }

        if (match) {
            displayStudent(&students[i]);
            found = true;
        }
    }

    if (!found) {
        printf("No matching students found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add new student record\n");
        printf("2. Delete a student record\n");
        printf("3. Display all student records\n");
        printf("4. Fill in marks of student\n");
        printf("5. Display report card of a specific student\n");
        printf("6. Search students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: displayAllStudents(); break;
            case 4: fillMarks(); break;
            case 5: displayReportCard(); break;
            case 6: searchStudents(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}