#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum string size
#define ASCII_SIZE 256 // Total number of possible ASCII characters

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0}; // Initialize all frequencies to 0
    int i, max_count;
    char max_char;

    printf("Enter any string: ");
    // Using fgets instead of gets for safe memory handling
    fgets(str, sizeof(str), stdin);

    // Remove newline character if appended by fgets
    str[strcspn(str, "\n")] = '\0';

    // Step 1: Count the frequency of each character
    i = 0;
    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    // Step 2: Find the character with the maximum frequency
    max_count = 0;
    max_char = str[0]; // Default fallback for empty or single-character strings

    for (i = 0; i < ASCII_SIZE; i++) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_char = (char)i;
        }
    }

    // Output the result
    if (max_count > 0) {
        printf("The maximum occurring character is '%c' and it appears %d times.\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
