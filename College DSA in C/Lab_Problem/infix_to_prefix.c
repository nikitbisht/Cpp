/*
Qn10:- Write a program in C to convert an infix Expression to a Prefix Expression usng the concept of stack?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define Max_Size 40
char infixExpression[Max_Size];
char stack[Max_Size];
char prefixExpression[Max_Size];
int top=-1;
//Operator push into Stack
void push(char ch){
    if(top==Max_Size-1){
        printf("Stack OverFlow\n");
        exit(0);
    }
    stack[++top]=ch;
}
//Remove Operator from Stack
char pop(){
    if(top==-1){
        printf("Stack UnderFlow\n");
        exit(0);
    }
    return stack[top--];
}
// peek Element in stack
char peek(){
    return stack[top];
}
//check its operand or not
bool isOprand(char ch){
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9'){
        return true;
    }
    return false;
}
//precedence of opertor
int precedence (char ch){
    switch (ch){
    case'*':
    case'/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '^':
        return 3;
    }
    return -1;
}
//Convert Infix to prefix
void infix_to_prefix(){
    int iIndex=0;
    int pIndex=0;
    while(infixExpression[iIndex]!='\0'){
        if(isOprand(infixExpression[iIndex])){
            prefixExpression[pIndex++]=infixExpression[iIndex];
        }
        else if(infixExpression[iIndex]=='('){
            push(infixExpression[iIndex]);
        }
        else if(infixExpression[iIndex]==')'){
            while(peek()!='('){
                prefixExpression[pIndex++]=pop();
            }
            pop();
        }
        else{
            if(precedence (peek())>=precedence (infixExpression[iIndex])){
                prefixExpression[pIndex++]=pop();
            }
            push(infixExpression[iIndex]);
        }
        iIndex++;
    }
    while(top!=-1){
        prefixExpression[pIndex++]=pop();
    }
}
//Reverse Expression
void reverse(char *expression){
    int front=0;
    int last=strlen(expression)-1;
    while(front<last){
        char temp=expression[front];
        expression[front++]=expression[last];
        expression[last--]=temp;
    }
}
//Invert Bracket
void invertBracket(){
    int n=strlen(infixExpression);
    for(int i=0;i<n;i++){
        if(infixExpression[i]=='('){
            infixExpression[i]=')';
        }
        else if(infixExpression[i]==')'){
            infixExpression[i]='(';
        }
    }
}
int main(){
    printf("Enter the infixExpression:- \n");
    scanf("%[^\n]s",infixExpression);
    reverse(infixExpression);
    invertBracket();
    infix_to_prefix();
    reverse(prefixExpression);
    printf("Prefix Expression:- \n");
    puts(prefixExpression);
    return 0;
}
/*
1.Input
Enter the infixExpression:- 
(x*y)-(z/p)
Output:
Prefix Expression:- 
-*xy/zp

2.Input:-
Enter the infixExpression:- 
(a+b)/(c-d)(e*f)/(g+h)
Output:
Prefix Expression:- 
/+ab/-cd*ef+gh

3.Input:-
Enter the infixExpression:- 
5*(13-5*3)/9
Output:
Prefix Expression:- 
*5/-13*539
*/