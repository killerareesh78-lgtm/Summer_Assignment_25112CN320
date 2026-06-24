#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0;
    int end;
    int isPalindrome = 1; // 1 means true, 0 means false

    printf("Enter a string: ");
    
    // Read string safely including spaces
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
    }

    // Find the last index of the string
    end = strlen(str) - 1;

    // Compare characters from both ends moving towards the center
    while (start < end) {
        if (str[start] != str[end]) {
            isPalindrome = 0; // Mismatch found
            break;
        }
        start++;
        end--;
    }

    // Output the final verification result
    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
