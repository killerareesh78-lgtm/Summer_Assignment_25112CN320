#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    // Size 256 covers all standard ASCII characters
    int freq[256] = {0}; 

    printf("Enter a string: ");
    // fgets is safer than gets() as it prevents buffer overflow
    fgets(str, sizeof(str), stdin); 

    // Loop through the string until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        // Exclude newline character added by fgets
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
    }

    printf("\nCharacter frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' occurs %d time(s)\n", i, freq[i]);
        }
    }

    return 0;
}
