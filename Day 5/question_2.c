#include <stdio.h>

int main() {
    int n, i, j, num, largestPrime = -1, isPrime;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        isPrime = 1;

        if (num <= 1)
            isPrime = 0;
        else {
            for (j = 2; j <= num / 2; j++) {
                if (num % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime && num > largestPrime)
            largestPrime = num;
    }

    if (largestPrime != -1)
        printf("Largest Prime Number = %d\n", largestPrime);
    else
        printf("No Prime Number Found\n");

    return 0;
}