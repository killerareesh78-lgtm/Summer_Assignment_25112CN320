#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int firstMatrix[50][50], secondMatrix[50][50], difference[50][50];

    // Ask user for matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Read the first matrix elements
    printf("\nEnter elements for the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Read the second matrix elements
    printf("\nEnter elements for the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Subtract the two matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            difference[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }

    // Print the resulting matrix
    printf("\nResultant Matrix (First - Second):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}
