#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function helper to safely read a string and remove the trailing newline character
void read_string(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0'; // Removes the trailing \n character
}

int main() {
    char str1[200], str2[100];
    int choice;

    while (1) {
        // Displaying Menu Options
        printf("\n=== STRING OPERATIONS SYSTEM ===\n");
        printf("1. Find Length of a String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("================================\n");
        printf("Enter your choice (1-6): ");
        
        // Read choice and check for invalid input formats
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        
        // Consume the trailing newline left by scanf before string reading
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                read_string(str1, sizeof(str1));
                printf("Length of the string: %lu\n", (unsigned long)strlen(str1));
                break;

            case 2:
                printf("Enter source string to copy: ");
                read_string(str1, sizeof(str1));
                strcpy(str2, str1);
                printf("Source String: %s\n", str1);
                printf("Copied String: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string to append: ");
                read_string(str2, sizeof(str2));
                
                // Safety check to avoid buffer overflow
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated Result: %s\n", str1);
                } else {
                    printf("Error: Combined string is too large for the buffer.\n");
                }
                break;

            case 4:
                printf("Enter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string: ");
                read_string(str2, sizeof(str2));
                
                int result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Result: Both strings are completely identical.\n");
                } else if (result > 0) {
                    printf("Result: First string is greater than second string (lexicographically).\n");
                } else {
                    printf("Result: Second string is greater than first string.\n");
                }
                break;

            case 5:
                printf("Enter a string to reverse: ");
                read_string(str1, sizeof(str1));
                
                int len = strlen(str1);
                printf("Reversed String: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Exiting the String Operations System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option selected! Please try again.\n");
        }
    }
    return 0;
}
