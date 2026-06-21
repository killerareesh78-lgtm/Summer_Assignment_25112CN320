#include <stdio.h>
#include <ctype.h> // Required for toupper()

int main() {
    char str[100];
    int i = 0;

    printf("Enter a string in lowercase: ");
    // Use fgets to safely read a line including spaces
    fgets(str, sizeof(str), stdin); 

    // Loop through each character until the null terminator
    while (str[i] != '\0') {
        str[i] = toupper((unsigned char)str[i]);
        i++;
    }

    printf("Uppercase string: %s", str);
    return 0;
}
