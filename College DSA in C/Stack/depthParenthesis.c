#include<stdio.h>
int main(){
	char s1[100];
	printf("Enter the string:- ");
	scanf("%[^\n]s",s1);
	int maxi=0,flag=0;
	int i=0;
	while(s1[i]!='\0'){
		if(s1[i]=='('){
			flag++;
			if(maxi<flag){
				maxi=flag;
			}	
		}
		else if(s1[i]==')'){
			flag--;
		}
		i++;
	}
	printf("%d",maxi);
		
	return 0;
}