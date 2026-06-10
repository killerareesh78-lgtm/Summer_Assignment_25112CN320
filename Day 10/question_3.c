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

        // Print ascending numbers
        for (col = 1; col <= row; col++)
        {
            printf("%d", col);
        }

        // Print descending numbers
        for (col = row - 1; col >= 1; col--)
        {
            printf("%d", col);
        }

        printf("\n");
    }

    return 0;
}