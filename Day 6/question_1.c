#include <stdio.h>

int main()
{
    int binary, remainder;
    int decimal = 0;
    int base = 1;

    // Input binary number
    printf("Enter a binary number: ");
    scanf("%d", &binary);

    // Convert binary to decimal
    while (binary > 0)
    {
        // Extract last digit
        remainder = binary % 10;

        // Add corresponding decimal value
        decimal = decimal + (remainder * base);

        // Update base (powers of 2)
        base = base * 2;

        // Remove last digit
        binary = binary / 10;
    }

    // Display result
    printf("Decimal Number = %d\n", decimal);

    return 0;
}