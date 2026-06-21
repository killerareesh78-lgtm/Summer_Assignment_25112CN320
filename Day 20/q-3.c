#include <stdio.h>

int main() {
    int rows, cols;
    int i, j;

    // Get the dimensions of the matrix from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Declare the matrix based on user input
    int matrix[rows][cols];

    // Read elements of the matrix from the user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the input matrix for clarity
    printf("\nThe Matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and print row-wise sum
    printf("\n--- Row-wise Sum Results ---\n");
    for (i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum to 0 for each new row
        
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; // Accumulate elements of the current row
        }
        
        printf("Sum of Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}
