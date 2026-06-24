#include <stdio.h>
#include <string.h>

#define MAX_NAMES 50
#define MAX_LENGTH 100

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n, i, j;

    // Ask user for the total number of names
    printf("Enter the number of names to sort (up to %d): ", MAX_NAMES);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }

    // Clear the input buffer to prevent issues with fgets
    while (getchar() != '\n');

    // Input names from user
    printf("Enter %d names (one per line):\n", n);
    for (i = 0; i < n; i++) {
        // Read string including spaces safely
        if (fgets(names[i], sizeof(names[i]), stdin) != NULL) {
            // Remove trailing newline character added by fgets
            names[i][strcspn(names[i], "\n")] = '\0';
        }
    }

    // Alphabetical Sorting using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // strcmp returns a positive number if names[j] comes after names[j+1]
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names using strcpy
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // Display the sorted results
    printf("\nAlphabetically Sorted Names:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}
