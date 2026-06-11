#include <stdio.h>

// Function to calculate factorial
long long factorial(int n)
{
    long long fact = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial of a negative number is not defined.\n");
    else
        printf("Factorial of %d is: %lld\n", num, factorial(num));

    return 0;
}