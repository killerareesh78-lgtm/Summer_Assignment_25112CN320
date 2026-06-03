#include<stdio.h>
int main(){
    int n,m,i,j,a;
    printf("Enter the first element of a range: ");
    scanf("%d",&m);
    printf("Enter the second element of a range: ");
    scanf("%d",&n);
    for(i=m;i<=n;i++){
        if(i<=1){
            continue;
        }
        a=0;
        for(j=2;j<=i-1;j++){
            if(i%j==0){
                a=1;
            break;
            }
           
        }
         if(a==0){
                printf("%d ",i);
            }
    }
    return 0;
}