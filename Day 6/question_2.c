#include <stdio.h>

int main()
{
    int decimal, remainder;
    int binary = 0;
    int base = 1;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    while (decimal > 0)
    {
        // Find remainder when divided by 2
        remainder = decimal % 2;

        // Add remainder at appropriate position
        binary = binary + (remainder * base);

        // Move to next digit position in binary number
        base = base * 10;

        // Update decimal number
        decimal = decimal / 2;
    }

    // Display binary equivalent
    printf("Binary Number = %d\n", binary);

    return 0;
}