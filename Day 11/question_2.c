#include <stdio.h>

// Function to find the maximum of two numbers
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("The maximum number is: %d\n", maximum(num1, num2));

    return 0;
}