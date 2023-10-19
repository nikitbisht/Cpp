//infix to prefix
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 20
char infix[Max_Size];
char postfix[Max_Size];
char stack[Max_Size];
int top=-1;
bool isOperand(char ch){
	if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9'){
		return true;
	}
	else
		return false;
}
void push(char ch){
	if(top==Max_Size-1){
		printf("Sack underflow");
		exit(0);
	}
	else{
		stack[++top]=ch;
	}
}
char pop(){
	if(top==-1){
		printf("Stack Overflow");
		exit(0);
	}
	else{
		return stack[top--];
	}
}
char peek(){
	return stack[top];
}
int precedence(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='+'||ch=='-')
		return 1;
	else 
		return -1;
}
void infixToPrefix(){
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='('){
			push(infix[i]);
		}
		else if(infix[i]==')'){
			while(peek()!='('){
				postfix[j++]=pop();
			}
			pop();
		}
		else{
			if(precedence(peek())>=precedence(infix[i])){
				postfix[j++]=pop();
			}
			push(infix[i]);
		}
		i++;
	}
	while(top!=-1){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
}

int main(){
	printf("Enter the expression:- ");
	scanf("%[^\n]s",infix);
	infixToPrefix();
	printf("%s",postfix);
	return 0;
}