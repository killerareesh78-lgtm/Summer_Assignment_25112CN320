#include<stdio.h>
int main(){
    int n,r,sum,num;
    printf("Enter the number: ");
    scanf("%d",&n);
    sum=0;
    num=n;
    while(n!=0){
        r=n%10;
        sum =sum+r;
        n=n/10;
    }
    printf("SUM OF DIGITS IN %d is %d",num,sum);
    return 0;
}