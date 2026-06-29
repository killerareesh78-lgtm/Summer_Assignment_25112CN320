#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    // Continuous loop for the menu interface
    do {
        // Displaying the Menu Layout
        printf("\n=============================\n");
        printf("    MENU-DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Terminate early if user picks exit
        if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
            break;
        }

        // Validate choice before asking for operands
        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        }

        // Processing operation based on menu choice
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                // Runtime protection: prevent crash from division by zero
                if (num2 != 0.0) {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is mathematically undefined.\n");
                }
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-5).\n");
        }

    } while (choice != 5);

    return 0;
}
