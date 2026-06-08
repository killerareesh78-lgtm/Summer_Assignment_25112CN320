#include <stdio.h>

int main()
{
    int rows, row, col;
    char alphabet;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print alphabet half pyramid
    for (row = 1; row <= rows; row++)
    {
        alphabet = 'A';

        for (col = 1; col <= row; col++)
        {
            printf("%c ", alphabet);
            alphabet++;
        }

        printf("\n");
    }

    return 0;
}