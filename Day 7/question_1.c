#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main()
{
    int num;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of %d = %d\n", num, factorial(num));
    }

    return 0;
}