#include<stdio.h>
int main(){
	int arr[]={1,2,3,5,3,1,90,41,4,73,6};
	int n,i,size,flag=0;
	size=sizeof(arr)/sizeof(arr[0]);
	printf("Enter element to search:\n");
	scanf("%d",&n);
	for(i=0;i<size;i++){
		if(arr[i]==n)
			printf("The element is present at %d",i);
			flag=1;
	
	}
	if(flag==0)
		printf("Given element is not present in the array");
}
