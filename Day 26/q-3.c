#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234; // Default PIN for the simulation
    int input_pin, choice, count = 0;
    float balance = 5000.00; // Starting balance
    float amount;
    char transaction = 'y';

    printf("=== WELCOME TO THE ATM SIMULATOR ===\n");

    // PIN Authentication Loop
    while (1) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &input_pin);

        if (input_pin == pin) {
            printf("\nPIN authenticated successfully!\n");
            break;
        } else {
            count++;
            if (count >= 3) {
                printf("Too many incorrect attempts. Your session is locked.\n");
                exit(0);
            }
            printf("Incorrect PIN. You have %d attempt(s) left.\n\n", 3 - count);
        }
    }

    // Main Transaction Menu
    do {
        printf("\n==============================");
        printf("\n          MAIN MENU           ");
        printf("\n==============================");
        printf("\n 1. Check Balance");
        printf("\n 2. Withdraw Cash");
        printf("\n 3. Deposit Cash");
        printf("\n 4. Exit");
        printf("\n==============================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- BALANCE INQUIRY ---");
                printf("\nYour current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("\n--- WITHDRAW CASH ---");
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                
                if (amount <= 0) {
                    printf("Error: Invalid withdrawal amount.\n");
                } else if (amount > balance) {
                    printf("Error: Insufficient balance.\n");
                } else {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                    printf("Your new balance is: $%.2f\n", balance);
                }
                break;
            case 3:
                printf("\n--- DEPOSIT CASH ---");
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                
                if (amount <= 0) {
                    printf("Error: Invalid deposit amount.\n");
                } else {
                    balance += amount;
                    printf("Successfully deposited $%.2f.\n", amount);
                    printf("Your new balance is: $%.2f\n", balance);
                }
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice. Please select a number from 1 to 4.\n");
        }

        // Ask if the user wants another transaction
        printf("\nDo you want to perform another transaction? (y/n): ");
        scanf(" %c", &transaction);

    } while (transaction == 'y' || transaction == 'Y');

    printf("\nThank you for using our ATM. Goodbye!\n");

    return 0;
}
