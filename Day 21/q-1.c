#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string (spaces allowed): ");
    // Reads a full line including spaces safely
    fgets(str, sizeof(str), stdin); 

    // Loop through the character array
    while (str[length] != '\0') {
        length++;
    }

    // Remove the newline character ('\n') from the total count if present
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }

    printf("The length of the string is: %d\n", length);

    return 0;
}
