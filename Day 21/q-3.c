#include <stdio.h>
#include <ctype.h>

int main() {
    char str[150];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    // Safely read a line of text, including spaces
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert the character to lowercase to simplify checking
        char ch = tolower(str[i]);

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
        // Check if the character is a valid alphabet (but not a vowel)
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    printf("\nTotal vowels: %d\n", vowels);
    printf("Total consonants: %d\n", consonants);

    return 0;
}
