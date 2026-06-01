#include<stdio.h>
int main(){
    int n,i,sum;
    printf("Enter the value of first N natural number: ");
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++){
        sum=sum+i;
    }
    printf("Sum of first %d natural numbers: %d",n ,sum);
    return 0;
}