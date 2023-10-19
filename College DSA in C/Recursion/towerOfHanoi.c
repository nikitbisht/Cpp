//Tower of hanoi
#include<stdio.h>
void towerOfHanoi(int n,char S,char D,char A){
	if(n==1){
		printf("\n%c-->%c",S,D);
		return ;
	}
	towerOfHanoi(n-1,S,A,D);
	printf("\n%c-->%c",S,D);
	towerOfHanoi(n-1,A,D,S);
}
int main(){
	int n;
	printf("Enter the number of disk:- ");
	scanf("%d",&n);
	towerOfHanoi(n,'A','C','B');
	return 0;
}