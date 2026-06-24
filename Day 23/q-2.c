#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // To handle all standard ASCII characters

// Function to find the character whose duplicate appears first
char findFirstRepeatingVariantA(char *str) {
    int visited[MAX_CHAR] = {0}; // Initialize lookup table with zeros

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        // If the character has been seen before, it's our first duplicate
        if (visited[ch] == 1) {
            return str[i];
        }
        
        // Mark character as seen
        visited[ch] = 1;
    }

    return '\0'; // Return null character if no repeating character exists
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Reads a line of text including spaces
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character from fgets if present
    str[strcspn(str, "\n")] = '\0';

    char result = findFirstRepeatingVariantA(str);

    if (result != '\0') {
        printf("The first repeating character (by duplicate appearance) is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
