#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if str2 is a rotation of str1
bool areRotations(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are different, they cannot be rotations of each other
    if (len1 != len2) {
        return false;
    }

    // Allocate memory for the concatenated string (len1 * 2 + 1 for '\0')
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Create the concatenated string: temp = str1 + str1
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of the concatenated string
    bool result = (strstr(temp, str2) != NULL);

    // Free the dynamically allocated memory
    free(temp);

    return result;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (areRotations(str1, str2)) {
        printf("Result: Yes, the strings are rotations of each other.\n");
    } else {
        printf("Result: No, the strings are NOT rotations of each other.\n");
    }

    return 0;
}
