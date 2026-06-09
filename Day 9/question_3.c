#include <stdio.h>

int main()
{
    int rows, row, col;
    char alphabet = 'A';

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print alphabet half pyramid
    for (row = 1; row <= rows; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%c ", alphabet);
        }

        printf("\n");
        alphabet++;
    }

    return 0;
}