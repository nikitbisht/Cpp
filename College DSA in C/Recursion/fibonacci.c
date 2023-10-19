#include<stdio.h>
int fibo(int n){
	if(n==1||n==0)
		return n;
	return fibo(n-1)+fibo(n-2);
}
int main(){
	int n;
	printf("Enter the number:- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf(" %d ",fibo(i));
	}
	return 0;
}