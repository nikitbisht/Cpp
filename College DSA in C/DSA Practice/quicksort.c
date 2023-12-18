//Quick Sort on charcter
#include<stdio.h>
//convert into upper case and check
int handle(char a, char b){
	a = (a>='a'&&a<='z')? a-'a'+'A':a;
	b = (b>='a'&&b<='z')? b-'a'+'A':b;
	if(a<b)	return -1;
	if(a>b)	return 1;
	return 0;
}
void swap(char* a,char* b){
	char ch = *a;
	*a = *b;
	*b = ch;
}
int partation(char str[],int start,int end){
	char pivot = str[end];
	int i = start-1;
	for(int j = start; j < end; j++){
		if(handle(str[j],pivot)<0){
			i++;
			swap(&str[i],&str[j]);
		}
	}
	swap(&str[i+1],&str[end]);
	return i+1;
}
void quickSort(char str[],int start,int end){
	//base case
	if(start>=end){
		return ;
	}
	int part = partation(str,start,end);
	quickSort(str,start,part-1);
	quickSort(str,part+1,end);
}
int getSize(char str[]){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
int main(){
	char str[100];
	int start = 0;
	printf("Enter the string:- ");
	scanf("%[^\n]s",str);
	int size = getSize(str);
	quickSort(str,start,size-1);
	printf("%s",str);
}