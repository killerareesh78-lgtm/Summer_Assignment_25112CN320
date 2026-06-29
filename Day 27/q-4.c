#include <stdio.h>
#include <string.h>

#define PASSING_MARK 40
#define TOTAL_SUBJECTS 5

// Structure to organize subject details dynamically
struct Subject {
    char name[30];
    int max_marks;
    int obtained_marks;
};

// Structure to encapsulate full student data
struct Student {
    char name[50];
    int roll_no;
    char course[20];
    struct Subject subjects[TOTAL_SUBJECTS];
    int total_obtained;
    int total_max;
    float percentage;
    char division[15];
    char status[5];
};

// Function prototypes to maintain structural clean code
void collectData(struct Student *s);
void performCalculations(struct Student *s);
void displayMarksheet(const struct Student *s);

int main() {
    struct Student student;

    printf("=========================================\n");
    printf("   STUDENT MARKSHEET GENERATION SYSTEM   \n");
    printf("=========================================\n");

    collectData(&student);
    performCalculations(&student);
    displayMarksheet(&student);

    return 0;
}

// Handles user console inputs safely
void collectData(struct Student *s) {
    // Initializing fixed academic subject metadata
    strcpy(s->subjects[0].name, "Mathematics");
    strcpy(s->subjects[1].name, "Physics");
    strcpy(s->subjects[2].name, "Chemistry");
    strcpy(s->subjects[3].name, "Computer Science");
    strcpy(s->subjects[4].name, "English");

    printf("Enter Student Name: ");
    scanf(" %[^\n]s", s->name); // Accepts spaced strings securely
    
    printf("Enter Roll Number: ");
    scanf("%d", &s->roll_no);
    
    printf("Enter Course Name: ");
    scanf(" %[^\n]s", s->course);

    printf("\n--- Enter Marks Obtained (Out of 100) ---\n");
    for (int i = 0; i < TOTAL_SUBJECTS; i++) {
        s->subjects[i].max_marks = 100;
        do {
            printf("%-18s: ", s->subjects[i].name);
            scanf("%d", &s->subjects[i].obtained_marks);
            
            if (s->subjects[i].obtained_marks < 0 || s->subjects[i].obtained_marks > 100) {
                printf("Invalid Input! Marks must be between 0 and 100.\n");
            }
        } while (s->subjects[i].obtained_marks < 0 || s->subjects[i].obtained_marks > 100);
    }
}

// Processes internal logic, flags failures, and assigns divisions
void performCalculations(struct Student *s) {
    s->total_obtained = 0;
    s->total_max = 0;
    int failed_any = 0;

    for (int i = 0; i < TOTAL_SUBJECTS; i++) {
        s->total_obtained += s->subjects[i].obtained_marks;
        s->total_max += s->subjects[i].max_marks;
        
        // Fail rule evaluation per individual subject
        if (s->subjects[i].obtained_marks < PASSING_MARK) {
            failed_any = 1;
        }
    }

    s->percentage = ((float)s->total_obtained / s->total_max) * 100;

    // Academic positioning based on evaluation rules
    if (failed_any) {
        strcpy(s->status, "FAIL");
        strcpy(s->division, "None");
    } else {
        strcpy(s->status, "PASS");
        if (s->percentage >= 60.0) {
            strcpy(s->division, "1st Division");
        } else if (s->percentage >= 50.0) {
            strcpy(s->division, "2nd Division");
        } else {
            strcpy(s->division, "3rd Division");
        }
    }
}

// Outputs a cleanly formatted, aligned console report card 
void displayMarksheet(const struct Student *s) {
    printf("\n\n");
    printf("=========================================================\n");
    printf("                  OFFICIAL MARKSHEET                     \n");
    printf("=========================================================\n");
    printf(" Name     : %-25s Roll No: %-10d\n", s->name, s->roll_no);
    printf(" Course   : %-25s Status : %-10s\n", s->course, s->status);
    printf("---------------------------------------------------------\n");
    printf(" %-20s | %-12s | %-12s\n", "SUBJECT", "MAX MARKS", "OBTAINED");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < TOTAL_SUBJECTS; i++) {
        printf(" %-20s | %-12d | %-12d %s\n", 
               s->subjects[i].name, 
               s->subjects[i].max_marks, 
               s->subjects[i].obtained_marks,
               (s->subjects[i].obtained_marks < PASSING_MARK) ? "*" : " ");
    }
    
    printf("---------------------------------------------------------\n");
    printf(" %-20s | %-12d | %-12d\n", "TOTAL", s->total_max, s->total_obtained);
    printf("---------------------------------------------------------\n");
    printf(" Percentage : %.2f%%\n", s->percentage);
    printf(" Division   : %s\n", s->division);
    if (strcmp(s->status, "FAIL") == 0) {
        printf(" Note       : (*) Indicates failure in that subject.\n");
    }
    printf("=========================================================\n");
}
