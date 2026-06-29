#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to store employee and salary details
struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Global variables to manage array state
struct Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

// Function prototypes
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void generatePayslip();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM     ");
        printf("\n=================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Generate Salary Payslip");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                generatePayslip();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Choose a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Automatically calculates earnings and deductions based on basic pay
void calculateSalary(struct Employee *emp) {
    emp->hra = emp->basic_salary * 0.15f;  // HRA is 15% of basic salary
    emp->da = emp->basic_salary * 0.20f;   // DA is 20% of basic salary
    emp->pf = emp->basic_salary * 0.12f;   // PF is 12% deduction

    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - emp->pf;
}

// Adds a unique employee to the system
void addEmployee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nSystem database full! Cannot add more records.\n");
        return;
    }

    struct Employee new_emp;
    int duplicate = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &new_emp.id);

    // Validate that the ID doesn't already exist
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == new_emp.id) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("\nError: An employee with ID %d already exists!\n", new_emp.id);
        return;
    }

    printf("Enter Employee Name: ");
    getchar(); // Clear the newline character from buffer
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Designation: ");
    fgets(new_emp.designation, sizeof(new_emp.designation), stdin);
    new_emp.designation[strcspn(new_emp.designation, "\n")] = 0;

    printf("Enter Basic Monthly Salary ($): ");
    scanf("%f", &new_emp.basic_salary);

    // Compute salary breakdown immediately
    calculateSalary(&new_emp);

    // Commit to data array
    employees[employee_count] = new_emp;
    employee_count++;

    printf("\nEmployee registered successfully!\n");
}

// Prints high-level overview table of all recorded instances
void displayAllEmployees() {
    if (employee_count == 0) {
        printf("\nNo data found! Please add an employee record first.\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-15s %-15s", "ID", "Name", "Designation", "Gross Pay", "Net Pay");
    printf("\n--------------------------------------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%-10d %-20s %-15s %-15.2f %-15.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, 
               employees[i].gross_salary, employees[i].net_salary);
    }
}

// Finds an employee file using individual tracking key
void searchEmployee() {
    if (employee_count == 0) {
        printf("\nNo data found! Database is empty.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == search_id) {
            printf("\n--- Record Found ---");
            printf("\nID:          %d", employees[i].id);
            printf("\nName:        %s", employees[i].name);
            printf("\nDesignation: %s", employees[i].designation);
            printf("\nBasic Pay:   $%.2f", employees[i].basic_salary);
            printf("\nNet TakeHome:$%.2f\n", employees[i].net_salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee record with ID %d not found.\n", search_id);
    }
}

// Generates an isolated financial slip breakdown
void generatePayslip() {
    if (employee_count == 0) {
        printf("\nNo records available to generate payslips.\n");
        return;
    }

    int target_id, found = 0;
    printf("\nEnter Employee ID for Payslip: ");
    scanf("%d", &target_id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == target_id) {
            found = 1;
            printf("\n=================================================");
            printf("\n              MONTHLY SALARY SLIP                ");
            printf("\n=================================================");
            printf("\n Emp ID: %-10d    Name: %-20s", employees[i].id, employees[i].name);
            printf("\n Desig:  %-10s", employees[i].designation);
            printf("\n-------------------------------------------------");
            printf("\n EARNINGS                        DEDUCTIONS       ");
            printf("\n Basic Pay:   $%10.2f       Provident Fund:$%7.2f", employees[i].basic_salary, employees[i].pf);
            printf("\n HRA (15%%):   $%10.2f", employees[i].hra);
            printf("\n DA (20%%):    $%10.2f", employees[i].da);
            printf("\n-------------------------------------------------");
            printf("\n GROSS PAY:   $%10.2f       TOTAL DED:     $%7.2f", employees[i].gross_salary, employees[i].pf);
            printf("\n=================================================");
            printf("\n NET TAKE-HOME PAY: $%10.2f", employees[i].net_salary);
            printf("\n=================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nNo system matches found for Employee ID: %d\n", target_id);
    }
}
