#include <stdio.h>

/* Function declaration */
int isPerfect(int num);

int main() {
    int number;

    /* Input standard number from the user */
    printf("Enter any positive integer: ");
    scanf("%d", &number);

    /* Call the function and check its return value */
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}

/**
 * Function to check whether a number is perfect or not.
 * Returns 1 if perfect, otherwise returns 0.
 */
int isPerfect(int num) {
    int i, sum = 0;

    /* Negative numbers, 0, and 1 are not perfect numbers */
    if (num <= 1) {
        return 0;
    }

    /* Loop running up to num/2 to find all proper divisors */
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; /* Add divisor to sum */
        }
    }

    /* If sum of proper divisors equals original number, it is perfect */
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}
