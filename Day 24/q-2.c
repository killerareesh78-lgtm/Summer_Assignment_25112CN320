#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compress the string
void compressString(const char *src, char *dest) {
    int i = 0;
    int destIndex = 0;
    int len = strlen(src);

    while (i < len) {
        // Store current character
        dest[destIndex++] = src[i];

        // Count occurrences of the current character
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        // Convert the count integer to a string and append it to dest
        int charsWritten = sprintf(&dest[destIndex], "%d", count);
        destIndex += charsWritten;

        i++;
    }

    // Append the null terminator to mark the end of the new string
    dest[destIndex] = '\0';
}

int main() {
    // Allocate a buffer large enough for user input
    char src[500];
    
    printf("Enter a string to compress: ");
    if (scanf("%499s", src) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    // Worst-case size allocation for compressed buffer (e.g., "abcdef" -> "a1b1c1d1e1f1\0")
    char *dest = (char *)malloc(strlen(src) * 2 + 1);
    if (dest == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Compress and display result
    compressString(src, dest);
    printf("Compressed string: %s\n", dest);

    // Clean up allocated memory
    free(dest);
    return 0;
}
