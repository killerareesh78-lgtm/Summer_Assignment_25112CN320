#include <stdio.h>

int main()
{
    int decimal;
    int binary = 0;
    int base = 1;
    int remainder;
    int setBits = 0;
    int originalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    originalNumber = decimal;

    // Convert decimal to binary
    while (decimal != 0)
    {
        remainder = decimal % 2;
        binary = binary + (remainder * base);
        base = base * 10;
        decimal = decimal / 2;
    }

    printf("Binary Number = %d\n", binary);

    // Create a copy of binary number for counting set bits
    int binaryCopy = binary;

    // Count the number of 1s in binary representation
    while (binaryCopy != 0)
    {
        if (binaryCopy % 10 == 1)
        {
            setBits++;
        }

        binaryCopy = binaryCopy / 10;
    }

    // Display result
    printf("Number of Set Bits in %d = %d\n",
           originalNumber, setBits);

    return 0;
}