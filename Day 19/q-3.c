#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int m[r][c], t[c][r];

    // Input
    for(i=0; i<r; i++)
        for(j=0; j<c; j++) {
            printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%d", &m[i][j]);
        }

    // Transpose
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            t[j][i] = m[i][j];

    // Output
    printf("\nTranspose:\n");
    for(i=0; i<c; i++)
        for(j=0; j<r; j++)
            printf("%d  ", t[i][j]);
        printf("\n");
    return 0;
}
