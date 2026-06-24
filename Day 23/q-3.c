#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to check if two strings are anagrams
bool check_anagram(const char *str1, const char *str2) {
    int count[256] = {0}; // Frequency array for all ASCII characters
    int i;

    // If lengths are not equal, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    // Count frequencies: increment for str1, decrement for str2
    for (i = 0; str1[i] != '\0'; i++) {
        // Convert to lowercase to make the check case-insensitive
        count[(unsigned char)tolower(str1[i])]++;
        count[(unsigned char)tolower(str2[i])]--;
    }

    // If all frequencies are zero, the strings are anagrams
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter the first string: ");
    // Read string including spaces, stripping the newline character
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (check_anagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}
