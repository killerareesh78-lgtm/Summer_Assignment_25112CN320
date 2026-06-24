#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char *str) {
    // Array to keep track of visited characters (ASCII size 256)
    bool seen[256] = { false };
    
    int targetIndex = 0; // Points to where the next unique character goes
    
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        
        // If the character hasn't been seen yet, keep it
        if (!seen[ch]) {
            seen[ch] = true;
            str[targetIndex] = str[i];
            targetIndex++;
        }
    }
    
    // Null-terminate the modified string
    str[targetIndex] = '\0';
}

int main() {
    // Note: Do not use a string literal directly like char *str = "..." 
    // because string literals are read-only in C. Use a char array instead.
    char str[] = "programming language";
    
    printf("Original string: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}
