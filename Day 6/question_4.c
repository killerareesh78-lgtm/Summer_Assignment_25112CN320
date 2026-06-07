#include <stdio.h>

int main()
{
    int base, exponent;
    int result = 1;
    int i;

    // Input base number
    printf("Enter the base number (x): ");
    scanf("%d", &base);

    // Input exponent
    printf("Enter the exponent (n): ");
    scanf("%d", &exponent);

    // Calculate x^n using repeated multiplication
    for (i = 1; i <= exponent; i++)
    {
        result = result * base;
    }

    // Display result
    printf("%d raised to the power %d = %d\n",
           base, exponent, result);

    return 0;
}