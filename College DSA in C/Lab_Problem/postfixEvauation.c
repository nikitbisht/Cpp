/*
Qn6:- Write a C program to evaluate a postfix expression and find out the result of the expressioin?
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define Max 30
int top=-1;
int stack[Max];
char str[Max];
int size;
void push(int data){
    if(top==size-1){
        printf("Stack Overflow");
        // exit(0);
    }
    else{
        stack[++top]=data;
    }
}
int pop(){
    if(top==-1){
        printf("Stack Underflow");
        // exit(0);
    }
    else{
        return stack[top--];
    }
}
bool isDigit(char ch){
    if(ch>='0'&&ch<='9'){
        return true;
    }
    return false;
}
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
        return true;
    }
    return false;
}
int prefixEvaluation(){
    int curIndex=0;
    int operand;
    while (str[curIndex]!='\0'){
        if(isDigit(str[curIndex])){
            operand=0;
            while(isDigit(str[curIndex])){
                operand=operand*10+(str[curIndex]-'0');
                curIndex++;
            }
            push(operand);
        }
        else if (isOperator(str[curIndex])){
            int op2=pop();
            int op1=pop();
            switch (str[curIndex]){
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1/op2);
                break;
            case '^':
                push(op1^op2);
                break;
            default:
                break;
            }
            curIndex++;
        }
        else{
            curIndex++;
        }
    }
    return pop();   
}
int main(){
    printf("Enter the Postfix Expression:- ");
    scanf("%[^\n]",str);
    size=strlen(str);
    printf("Prefix Evaluation is :- %d",prefixEvaluation());
    return 0;
}
/*
1.Input:-
Enter the Postfix Expression:- 5 6 2 + * 12 4 / -
Output:
Prefix Evaluation is :- 37

2.Input:-
Enter the Postfix Expression:- 10 5 + 18 12 - *
Output:
Prefix Evaluation is :- 90

3.Input:-
Enter the Postfix Expression:- 100 50 + 2 * 200 -
Output:
Prefix Evaluation is :- 100
*/