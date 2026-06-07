#include <stdio.h>

// Global variable to store the reversed number
int reversedNumber = 0;

// Recursive function to reverse a number
int reverseNumber(int number)
{
    // Base case
    if (number == 0)
    {
        return reversedNumber;
    }

    // Extract last digit and append it to reversed number
    reversedNumber = reversedNumber * 10 + (number % 10);

    // Recursive call with remaining digits
    return reverseNumber(number / 10);
}

int main()
{
    int number;

    // Input number from user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Display reversed number
    printf("Reversed Number = %d\n", reverseNumber(number));

    return 0;
}