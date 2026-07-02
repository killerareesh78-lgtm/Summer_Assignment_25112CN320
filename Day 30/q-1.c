#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure representing a single student record
struct Student {
    int roll_no;
    char name[NAME_LENGTH]; // Array of characters (string) for name
    float gpa;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(const struct Student students[], int count);
void searchStudent(const struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS]; // Array of structures to store records
    int studentCount = 0;                  // Keeps track of the current number of records
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Consume remaining newline character left in input buffer by scanf
        getchar(); 

        switch (choice) {
            case 1:
                addStudent(database, &studentCount);
                break;
            case 2:
                displayStudents(database, studentCount);
                break;
            case 3:
                searchStudent(database, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new student record
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more records.\n");
        return;
    }

    struct Student newStudent;

    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.roll_no);
    getchar(); // Clear buffer

    // Check for duplicate roll numbers
    for (int i = 0; i < *count; i++) {
        if (students[i].roll_no == newStudent.roll_no) {
            printf("Error: A student with Roll Number %d already exists!\n", newStudent.roll_no);
            return;
        }
    }

    printf("Enter Student Name: ");
    // Read string including spaces; remove trailing newline
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; 

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    // Save into the array and increment total count
    students[*count] = newStudent;
    (*count)++;

    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n--------------------------------------------------\n");
    printf("%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-5.2f\n", students[i].roll_no, students[i].name, students[i].gpa);
    }
    printf("--------------------------------------------------\n");
}

// Function to search for a specific student record
void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetRoll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].roll_no);
            printf("Name       : %s\n", students[i].name);
            printf("GPA        : %.2f\n", students[i].gpa);
            return; // Exit function early if match is found
        }
    }

    printf("Student with Roll Number %d not found.\n", targetRoll);
}
