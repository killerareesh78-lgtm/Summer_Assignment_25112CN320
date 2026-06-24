#include <stdio.h>

int main() {
    int age;

    // Prompt user for input
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check voting eligibility
    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote yet.\n");
        printf("You need to wait %d more year(s).\n", 18 - age);
    }

    return 0;
}
