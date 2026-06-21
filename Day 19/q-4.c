#include <stdio.h>

int main() {
    int size, i, j;
    int principal_sum = 0;
    int secondary_sum = 0;

    // Get matrix size from the user
    printf("Enter the size of the square matrix (e.g., 3 for 3x3): ");
    scanf("%d", &size);

    int matrix[size][size];

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate diagonal sums using a single efficient loop
    for (i = 0; i < size; i++) {
        // Principal diagonal condition: row index == column index (i == j)
        principal_sum += matrix[i][i];

        // Secondary diagonal condition: row index + column index == size - 1
        secondary_sum += matrix[i][size - 1 - i];
    }

    // Display the results
    printf("\n--- Result ---\n");
    printf("Sum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}
