#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[256];
    char longest_word[256] = "";
    char current_word[256] = "";
    
    int current_len = 0;
    int max_len = 0;
    
    printf("Enter a sentence: ");
    // Safely read standard input including spaces
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    // Parse the string character by character
    for (int i = 0; sentence[i] != '\0'; i++) {
        // Check if character belongs to a word (alphanumeric)
        if (isalnum(sentence[i])) {
            current_word[current_len] = sentence[i];
            current_len++;
        } 
        // End of a word reached (space, punctuation, or newline)
        else {
            if (current_len > 0) {
                // Null-terminate the current tracked word
                current_word[current_len] = '\0';
                
                // Compare lengths and update if a longer word is found
                if (current_len > max_len) {
                    max_len = current_len;
                    strcpy(longest_word, current_word);
                }
                
                // Reset counter for the next word
                current_len = 0;
            }
        }
    }

    // Handle edge case if the string didn't end with a delimiter
    if (current_len > max_len) {
        current_word[current_len] = '\0';
        max_len = current_len;
        strcpy(longest_word, current_word);
    }

    // Print the final result
    if (max_len > 0) {
        printf("The longest word is: %s\n", longest_word);
        printf("Length: %d\n", max_len);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}
