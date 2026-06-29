#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

// Structure to hold account details
typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} Account;

// Global array and account counter
Account bank[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
int findAccountIndex(int accNum);

int main() {
    int choice;

    while (1) {
        printf("\n=== BANK ACCOUNT MANAGEMENT SYSTEM ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Thank you for using our banking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to safely create a unique bank account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Error: System storage full. Cannot create more accounts.\n");
        return;
    }

    int accNum;
    printf("\nEnter a unique 4-digit Account Number: ");
    scanf("%d", &accNum);

    // Validate if the account number already exists
    if (findAccountIndex(accNum) != -1) {
        printf("Error: Account number %d already exists!\n", accNum);
        return;
    }

    bank[totalAccounts].accountNumber = accNum;

    printf("Enter Account Holder Name: ");
    getchar(); // Clear the dangling newline character from previous scanf
    fgets(bank[totalAccounts].name, NAME_LENGTH, stdin);
    bank[totalAccounts].name[strcspn(bank[totalAccounts].name, "\n")] = 0; // Remove newline character

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &bank[totalAccounts].balance);

    if (bank[totalAccounts].balance < 0) {
        printf("Error: Initial deposit cannot be negative. Setting balance to $0.00.\n");
        bank[totalAccounts].balance = 0.0;
    }

    printf("Success: Account created successfully for %s!\n", bank[totalAccounts].name);
    totalAccounts++;
}

// Function to handle deposits
void depositMoney() {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Deposit Amount: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    bank[index].balance += amount;
    printf("Success: deposited $%.2f. New Balance: $%.2f\n", amount, bank[index].balance);
}

// Function to handle withdrawals
void withdrawMoney() {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Withdrawal Amount: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > bank[index].balance) {
        printf("Error: Insufficient funds! Current balance is $%.2f\n", bank[index].balance);
        return;
    }

    bank[index].balance -= amount;
    printf("Success: Withdrew $%.2f. Remaining Balance: $%.2f\n", amount, bank[index].balance);
}

// Function to query balance
void checkBalance() {
    int accNum;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", bank[index].accountNumber);
    printf("Holder Name   : %s\n", bank[index].name);
    printf("Current Balance: $%.2f\n", bank[index].balance);
}

// Helper function to search for an account index via its number
int findAccountIndex(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i; // Return array position if found
        }
    }
    return -1; // Return -1 if account does not exist
}
