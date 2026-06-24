#include <stdio.h>
#include <stdbool.h>

int main() {
    char sentence[1000];
    int count = 0;
    bool in_word = false;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        // Check if the current character is not a space, tab, or newline
        if (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n' && sentence[i] != '\r') {
            if (!in_word) {
                in_word = true;
                count++;
            }
        } else {
            in_word = false;
        }
    }

    printf("Total number of words: %d\n", count);

    return 0;
}
