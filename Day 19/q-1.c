#include <stdio.h>

int main() {
    int rows, cols, i, j;
    
    // 1. Get matrix dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Declare the matrices based on user-defined sizes
    int matrixA[rows][cols];
    int matrixB[rows][cols];
    int sumMatrix[rows][cols];
    
    // 2. Input elements for the first matrix
    printf("\nEnter elements of the first matrix (Matrix A):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    // 3. Input elements for the second matrix
    printf("\nEnter elements of the second matrix (Matrix B):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    // 4. Add the corresponding elements of both matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    // 5. Display the resulting sum matrix
    printf("\nResultant Matrix (Matrix A + Matrix B):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", sumMatrix[i][j]);
        }
        printf("\n"); // Newline after completing each row
    }
    
    return 0;
}
