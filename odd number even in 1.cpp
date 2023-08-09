#include <stdio.h>
int main() {
int n,res=1,i,temp;
temp=n;
printf("Enter a number:\n");
scanf("%d",&n);
for(i=1;i<=n;i++){
	res*=i;
}
printf("Factorial of %d is %d",n,res);
return 0;
}
