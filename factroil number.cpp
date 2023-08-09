#include<stdio.h>
int main(){
	int a=0,b=1,temp,n,i;
	printf("Enter the value of N:\n");
	scanf("%d",&n);
	n=n-2;
	printf("0 1 ");
	for(i=0;i<n;i++){
		temp=a+b;
		a=b;b=temp;
		printf("%d ",temp);
	}
}
