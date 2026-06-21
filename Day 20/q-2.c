#include <stdio.h>

int main() {
    int rows, cols;
    int i, j;
    int isSymmetric = 1; // Flag variable: 1 means symmetric, 0 means not symmetric

    // 1. Get matrix dimensions from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // 2. A symmetric matrix MUST be a square matrix
    if (rows != cols) {
        printf("\nThe matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    int matrix[rows][cols];

    // 3. Input matrix elements
    printf("\nEnter the elements of the %dx%d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Check for symmetry by comparing elements across the main diagonal
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // Compare element at (i, j) with element at (j, i)
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;           // Exit the inner loop
            }
        }
        if (!isSymmetric) {
            break; // Exit the outer loop early
        }
    }

    // 5. Print the final result
    if (isSymmetric == 1) {
        printf("\nThe given matrix is a SYMMETRIC matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a symmetric matrix.\n");
    }

    return 0;
}
