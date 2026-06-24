#include <stdio.h>   // Required for printf() and scanf()
#include <stdlib.h>  // Required for rand() and srand()
#include <time.h>    // Required for time() to seed the generator

int main() {
    int secret_number;
    int user_guess;
    int attempts = 0;

    // 1. Seed the random number generator using the current system time
    srand(time(NULL));

    // 2. Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("===================================\n");
    printf("   WELCOME TO THE GUESSING GAME!   \n");
    printf("===================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // 3. Game loop using a do-while structure
    do {
        printf("Enter your guess: ");
        
        // Validate that the user inputs an actual integer
        if (scanf("%d", &user_guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            // Clear the invalid input buffer to avoid an infinite loop
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        // 4. Compare the guess with the secret number
        if (user_guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } 
        else if (user_guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } 
        else {
            printf("\n🎉 CONGRATULATIONS! You guessed it right!\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you %d attempts to win.\n", attempts);
        }

    } while (user_guess != secret_number);

    return 0;
}
