#include<stdio.h>
int main ()
{
int n, rev=0,rem,orig;
printf("Enter a number");
scanf("%d",&n);
orig=n;
while(n>0)
{
    rem=n%10;
    rev=rev*10+ rem;
    n=n/10;
}
if(orig==rev)
printf("%d is a palindrome nuber.", orig);
else
printf("%d is a Not palindrome nuber.",orig);
return 0;
}