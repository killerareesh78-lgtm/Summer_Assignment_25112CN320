#include<stdio.h>
int main(){
    int n,r,num,temp=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    num=n;
    while(n!=0){
        r=n%10;
        temp=temp*10+r;
        n=n/10;
    }
    if(num==temp){
        printf("Given number is a palindrome");
    }

    else{
        printf("Given number is not a palindrome");
    }
    return 0;
}