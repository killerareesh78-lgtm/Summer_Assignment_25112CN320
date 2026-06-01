#include<stdio.h>
int main(){
    int n,count=0,num;
     printf("enter number: ");
    scanf("%d",&n);
    num=n;
    while(n!=0){
        count++;
        n=n/10;
    }
    printf("number of digits in %d is %d",num,count);
    return 0;
}