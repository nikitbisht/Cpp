/*
Qn9:- Write a program in C to convert an infix infixExpression to a postfix infixExpression usng the concept of stack?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 40
char infixExpression[Max_Size];
char stack[Max_Size];
char postfixExpression[Max_Size];
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
void infix_to_postfix(){
    int iIndex=0;
    int pIndex=0;
    while(infixExpression[iIndex]!='\0'){
        if(isOprand(infixExpression[iIndex])){
            postfixExpression[pIndex++]=infixExpression[iIndex];
        }
        else if(infixExpression[iIndex]=='('){
            push(infixExpression[iIndex]);
        }
        else if(infixExpression[iIndex]==')'){
            while(peek()!='('){
                postfixExpression[pIndex++]=pop();
            }
            pop();
        }
        else{
            if(precedence (peek())>=precedence (infixExpression[iIndex])){
                postfixExpression[pIndex++]=pop();
            }
            push(infixExpression[iIndex]);
        }
        iIndex++;
    }
    while(top!=-1){
        postfixExpression[pIndex++]=pop();
    }
}
int main(){
    printf("Enter the infixExpression:- \n");
    scanf("%[^\n]s",infixExpression);
    infix_to_postfix();
    printf("Postfix Expression:- \n");
    puts(postfixExpression);
    return 0;
}
/*
1.Input:- 
Enter the infixExpression:-
5*(13-4*3)/6
Output:
Postfix Expression:- 
51343*-*6/

2.Input:- 
Enter the infixExpression:- 
(a+b)/(c-d)+(e*f)/(g+h)
Output:
Postfix Expression:- 
ab+cd-/ef*gh+/+

3.Input:-
Enter the infixExpression:- 
5*(6+2)-(10/4)
Output:
Postfix Expression:- 
562+*104/-
*/