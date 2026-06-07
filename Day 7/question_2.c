#include <stdio.h>

// Function to find nth Fibonacci term using recursion
int fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    // Input number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    // Print Fibonacci series
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}