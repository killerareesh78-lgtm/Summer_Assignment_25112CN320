#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows/cols for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows/cols for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Incompatible dimensions.\n");
        return 1;
    }

    int m1[r1][c1], m2[r2][c2], res[r1][c2];
    // Input for matrices omitted for brevity...

    // Multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) res[i][j] += m1[i][k] * m2[k][j];
        }
    }
    // Output for matrix omitted for brevity...
    return 0;
}
