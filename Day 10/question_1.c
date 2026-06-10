#include <stdio.h>

int main()
{
    int rows, row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (row = 1; row <= rows; row++)
    {
        // Print spaces
        for (col = 1; col <= rows - row; col++)
        {
            printf(" ");
        }

        // Print stars
        for (col = 1; col <= (2 * row - 1); col++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}