#include<stdio.h>
int main(){
    int n,rev,r,num;
    printf("ENTER THE NUMBER: ");
    scanf("%d",&n);
    rev=0;
    num=n;
    while(n!=0){
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    printf("reverse of %d is %d", num ,rev);
    return 0;
}