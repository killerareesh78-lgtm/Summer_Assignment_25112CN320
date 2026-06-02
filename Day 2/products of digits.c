#include<stdio.h>
int main(){
    int n,r,prod=1,num;
    printf("ENTER THE NUMBER: ");
    scanf("%d",&n);
    num=n;
    while(n!=0){
        r=n%10;
        prod=prod*r;
        n=n/10;
    }
    printf("Product of digits in %d is %d", num, prod);
    return 0;
}