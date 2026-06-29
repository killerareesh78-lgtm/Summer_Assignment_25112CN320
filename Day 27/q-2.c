#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Global variables to track the database state
Employee empList[MAX_EMPLOYEES];
int employeeCount = 0;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n==================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                modifyEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely clear standard input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a new employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nDatabase full! Cannot add more employees.\n");
        return;
    }

    Employee newEmp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmp.id);

    // Validate if the ID already exists
    for (int i = 0; i < employeeCount; i++) {
        if (empList[i].id == newEmp.id) {
            printf("\nError: An employee with ID %d already exists!\n", newEmp.id);
            return;
        }
    }

    clearInputBuffer();
    printf("Enter Name: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &newEmp.salary);

    empList[employeeCount] = newEmp;
    employeeCount++;
    printf("\nEmployee record added successfully!\n");
}

// 2. Display all employee records
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------");
    printf("\n%-10s %-25s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n-------------------------------------------------------------------");
    for (int i = 0; i < employeeCount; i++) {
        printf("\n%-10d %-25s %-20s $%-9.2f", 
               empList[i].id, empList[i].name, empList[i].designation, empList[i].salary);
    }
    printf("\n-------------------------------------------------------------------\n");
}

// 3. Search an employee by ID
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (empList[i].id == searchId) {
            printf("\n--- Employee Record Found ---");
            printf("\nID:          %d", empList[i].id);
            printf("\nName:        %s", empList[i].name);
            printf("\nDesignation: %s", empList[i].designation);
            printf("\nSalary:      $%.2f\n", empList[i].salary);
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", searchId);
}

// 4. Modify an existing record
void modifyEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found in the database.\n");
        return;
    }

    int targetId;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);

    for (int i = 0; i < employeeCount; i++) {
        if (empList[i].id == targetId) {
            printf("\n--- Editing Record for ID %d ---", targetId);
            
            clearInputBuffer();
            printf("\nEnter New Name: ");
            fgets(empList[i].name, sizeof(empList[i].name), stdin);
            empList[i].name[strcspn(empList[i].name, "\n")] = '\0';

            printf("Enter New Designation: ");
            fgets(empList[i].designation, sizeof(empList[i].designation), stdin);
            empList[i].designation[strcspn(empList[i].designation, "\n")] = '\0';

            printf("Enter New Salary: ");
            scanf("%f", &empList[i].salary);

            printf("\nEmployee record updated successfully!\n");
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", targetId);
}

// 5. Delete an employee record
void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (empList[i].id == deleteId) {
            // Shift remaining records to fill the deleted index space
            for (int j = i; j < employeeCount - 1; j++) {
                empList[j] = empList[j + 1];
            }
            employeeCount--;
            printf("\nEmployee record deleted successfully!\n");
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", deleteId);
}
