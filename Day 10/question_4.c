#include <stdio.h>

int main()
{
    int rows, row, col;
    char ch;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (row = 1; row <= rows; row++)
    {
        // Print spaces
        for (col = 1; col <= rows - row; col++)
        {
            printf(" ");
        }

        // Print ascending characters
        ch = 'A';
        for (col = 1; col <= row; col++)
        {
            printf("%c", ch);
            ch++;
        }

        // Print descending characters
        ch -= 2;
        while (ch >= 'A')
        {
            printf("%c", ch);
            ch--;
        }

        printf("\n");
    }

    return 0;
}