#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the structure for storing student details
typedef struct {
    int rollNumber;
    char name[50];
    float gpa;
} Student;

// Global array and counter to manage data in memory
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database full! Cannot add more student records.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    // Validate if the roll number already exists
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Error: A student with Roll Number %d already exists.\n", roll);
            return;
        }
    }

    students[studentCount].rollNumber = roll;
    clearInputBuffer(); // Clean buffer before reading string

    printf("Enter Student Name: ");
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter CGPA: ");
    scanf("%f", &students[studentCount].gpa);

    studentCount++;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-15s %-30s %-10s\n", "Roll Number", "Name", "CGPA");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-15d %-30s %-10.2f\n", students[i].rollNumber, students[i].name, students[i].gpa);
    }
}

// Function to search for a student using their roll number
void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("CGPA:        %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

// Function to update fields of an existing student record
void updateStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nCurrent details: Name: %s, CGPA: %.2f\n", students[i].name, students[i].gpa);
            clearInputBuffer();

            printf("Enter New Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New CGPA: ");
            scanf("%f", &students[i].gpa);

            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

// Function to delete a student record by roll number
void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            // Shift elements forward to overwrite deleted record
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

// Helper utility to safely flush standard input stream
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
