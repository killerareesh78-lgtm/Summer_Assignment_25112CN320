#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // To handle all standard ASCII characters

void findCommonCharacters(char *str1, char *str2) {
    int count1[MAX_CHAR] = {0};
    int count2[MAX_CHAR] = {0};
    int found = 0;

    // Count character frequencies in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)str1[i]]++;
    }

    // Count character frequencies in the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        count2[(unsigned char)str2[i]]++;
    }

    printf("Common characters: ");

    // Compare frequencies and print common characters
    for (int i = 0; i < MAX_CHAR; i++) {
        // Skip spaces if you don't want to treat them as common visible characters
        if (i == ' ') {
            continue;
        }

        if (count1[i] > 0 && count2[i] > 0) {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    // Define two example strings
    char string1[] = "hello world";
    char string2[] = "world series";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    // Call the function to find intersection
    findCommonCharacters(string1, string2);

    return 0;
}
