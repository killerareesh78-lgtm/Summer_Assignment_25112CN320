#include <stdio.h>

int main() {
    int rows, cols;
    
    // Accept matrix dimensions from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    
    // Accept matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Display the entered matrix
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Calculate and display column-wise sum
    printf("\n--- Column-wise Sum ---\n");
    for (int j = 0; j < cols; j++) {
        int colSum = 0; // Reset sum for each new column
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j]; // Accumulate sum down the column
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }
    
    return 0;
}
