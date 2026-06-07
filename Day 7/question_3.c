#include <stdio.h>

// Function to find sum of digits using recursion
int sumOfDigits(int n)
{
    // Base case
    if (n == 0)
        return 0;

    // Recursive case
    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int num;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Display result
    printf("Sum of digits = %d\n", sumOfDigits(num));

    return 0;
}