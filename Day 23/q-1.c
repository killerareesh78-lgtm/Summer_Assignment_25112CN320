#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

// Function to find the first non-repeating character
char findFirstNonRepeating(char *str) {
    int frequency[MAX_CHAR] = {0};
    int i;

    // Step 1: Count the frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        frequency[(unsigned char)str[i]]++;
    }

    // Step 2: Find the first character with a frequency of 1
    for (i = 0; str[i] != '\0'; i++) {
        if (frequency[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first unique character found
        }
    }

    // Return null character if no non-repeating character exists
    return '\0'; 
}

int main() {
    char str[100];
    char result;

    printf("Enter a string: ");
    // Read string including spaces safely
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character added by fgets if present
    str[strcspn(str, "\n")] = '\0';

    result = findFirstNonRepeating(str);

    if (result != '\0') {
        printf("The first non-repeating character is: '%c'\n", result);
    } else {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
