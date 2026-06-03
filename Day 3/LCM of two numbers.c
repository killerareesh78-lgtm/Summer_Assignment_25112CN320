#include<stdio.h>

int main() {
    int a, b, temp, x, y, gcd, lcm;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    x = a;
    y = b;

    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    gcd = a;
    lcm = (x * y) / gcd;

    printf("LCM = %d", lcm);

    return 0;
}