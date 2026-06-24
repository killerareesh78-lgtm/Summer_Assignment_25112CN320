#include <stdio.h>

// Function to remove all spaces from a string in-place
void removeSpaces(char *str) {
    int readIdx = 0;   // Pointer to scan the original string
    int writeIdx = 0;  // Pointer to track the position of non-space characters

    // Loop through the string until the null terminator is reached
    while (str[readIdx] != '\0') {
        // If the current character is not a space, shift it forward
        if (str[readIdx] != ' ') {
            str[writeIdx] = str[readIdx];
            writeIdx++;
        }
        readIdx++;
    }

    // Explicitly add the null terminator to mark the new end of the string
    str[writeIdx] = '\0';
}

int main() {
    // Array initialized with extra space to accommodate safe user input
    char text[200];

    printf("Enter a string with spaces: ");
    
    // fgets is used instead of scanf to read a full sentence containing spaces safely
    if (fgets(text, sizeof(text), stdin) != NULL) {
        
        // Remove spaces
        removeSpaces(text);

        // Display the modified string
        printf("String after removing spaces: %s", text);
    }

    return 0;
}
