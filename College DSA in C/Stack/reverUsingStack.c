//Reverse Stirng using Stack
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 50
char stack[Max_Size];
int top=-1;
void push(char ch){
	if(top==Max_Size-1){	
		printf("Stack Overflow");
		exit(0);
	}
	else{
		stack[++top]=ch;
	}
}
char pop(){
	if(top==-1){
		printf("Stack Underflow");
		exit(0);
	}
	return stack[top--];
}
int main(){
	char str[Max_Size];
	printf("Enter the String:- ");
	scanf("%[^\n]s",str);
	// Push Every charcter of string into stack
	int i=0;
	while(str[i]!='\0'){
		push(str[i]);
		i++;
	}
	printf("Previous String:- %s\n",str);
	//as we know that stack has LIFO principle 
	// so we take character from the stack and place it into string
	i=0;
	while(top!=-1){
		str[i++]=pop();
	}
	printf("Modify String:- %s\n",str);
	return 0;
}