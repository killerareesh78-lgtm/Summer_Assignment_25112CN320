#include <stdio.h>

int main()
{
    int rows, row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print inverted star half pyramid
    for (row = rows; row >= 1; row--)
    {
        for (col = 1; col <= row; col++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}