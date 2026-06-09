#include <stdio.h>

int main()
{
    int side, row, col;

    printf("Enter the length of side of the square: ");
    scanf("%d", &side);

    // Print hollow square pattern
    for (row = 1; row <= side; row++)
    {
        for (col = 1; col <= side; col++)
        {
            if (row == 1 || row == side || col == 1 || col == side)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    return 0;
}
