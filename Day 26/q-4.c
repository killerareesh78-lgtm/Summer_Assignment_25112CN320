#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 4

// Structure to store a single quiz question
typedef struct {
    char question_text[150];
    char options[4][50];
    char correct_option;
} QuizQuestion;

// Function prototypes
void display_welcome_message();
void load_questions(QuizQuestion quiz[]);
void run_quiz(QuizQuestion quiz[], int *score);
void display_results(int score, int total);

int main() {
    QuizQuestion quiz[TOTAL_QUESTIONS];
    int final_score = 0;

    display_welcome_message();
    load_questions(quiz);
    run_quiz(quiz, &final_score);
    display_results(final_score, TOTAL_QUESTIONS);

    return 0;
}

// Displays the initial game menu
void display_welcome_message() {
    printf("=========================================\n");
    printf("      WELCOME TO THE COMPUTER QUIZ       \n");
    printf("=========================================\n");
    printf("Instructions: Answer by typing A, B, C, or D.\n");
    printf("Press ENTER to start the quiz...\n");
    getchar(); 
    system("clear || cls"); // Clears terminal screen for both Unix and Windows
}

// Populates the quiz data structure array
void load_questions(QuizQuestion quiz[]) {
    // Question 1
    snprintf(quiz[0].question_text, 150, "Which programming language is known as the 'Mother of languages'?");
    snprintf(quiz[0].options[0], 50, "A) Assembly");
    snprintf(quiz[0].options[1], 50, "B) C");
    snprintf(quiz[0].options[2], 50, "C) Fortran");
    snprintf(quiz[0].options[3], 50, "D) COBOL");
    quiz[0].correct_option = 'B';

    // Question 2
    snprintf(quiz[1].question_text, 150, "What does CPU stand for?");
    snprintf(quiz[1].options[0], 50, "A) Computer Processing Unit");
    snprintf(quiz[1].options[1], 50, "B) Central Peripheral Unit");
    snprintf(quiz[1].options[2], 50, "C) Central Processing Unit");
    snprintf(quiz[1].options[3], 50, "D) Core Processing Utility");
    quiz[1].correct_option = 'C';

    // Question 3
    snprintf(quiz[2].question_text, 150, "Which data structure operates on a Last-In, First-Out (LIFO) basis?");
    snprintf(quiz[2].options[0], 50, "A) Queue");
    snprintf(quiz[2].options[1], 50, "B) Array");
    snprintf(quiz[2].options[2], 50, "C) Linked List");
    snprintf(quiz[2].options[3], 50, "D) Stack");
    quiz[2].correct_option = 'D';

    // Question 4
    snprintf(quiz[3].question_text, 150, "What is the primary function of an Operating System?");
    snprintf(quiz[3].options[0], 50, "A) Database Management");
    snprintf(quiz[3].options[1], 50, "B) Resource Allocation and Hardware Management");
    snprintf(quiz[3].options[2], 50, "C) Web Browsing");
    snprintf(quiz[3].options[3], 50, "D) Compiling Source Code");
    quiz[3].correct_option = 'B';
}

// Iterates through questions and handles user input evaluation
void run_quiz(QuizQuestion quiz[], int *score) {
    char user_answer;

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, quiz[i].question_text);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Loop to enforce valid input validation (A, B, C, or D)
        while (1) {
            printf("Your Answer: ");
            scanf(" %c", &user_answer);
            user_answer = toupper(user_answer); // Automatically fixes lowercase entries

            if (user_answer >= 'A' && user_answer <= 'D') {
                break;
            }
            printf("Invalid selection! Please enter A, B, C, or D.\n");
        }

        // Evaluate answer
        if (user_answer == quiz[i].correct_option) {
            printf("CORRECT!\n");
            (*score)++;
        } else {
            printf("WRONG! The correct answer was %c.\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n");
    }
}

// Computes metrics and displays final score
void display_results(int score, int total) {
    float percentage = ((float)score / total) * 100;
    
    printf("\n=========================================\n");
    printf("               QUIZ RESULTS              \n");
    printf("=========================================\n");
    printf("Final Score: %d out of %d\n", score, total);
    printf("Percentage: %.2f%%\n", percentage);
    
    if (percentage >= 75.0) {
        printf("Performance: Excellent Job!\n");
    } else if (percentage >= 50.0) {
        printf("Performance: Good Effort!\n");
    } else {
        printf("Performance: Keep Practicing!\n");
    }
    printf("=========================================\n");
}
