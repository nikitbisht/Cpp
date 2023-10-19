#include<stdio.h>
#include<stdlib.h>
#define Max_Size 40
char expression[Max_Size];
char stack[Max_Size];
int top=-1;
//Push into stack
void push(char ch){
    if(top==Max_Size-1){
        printf("Stack overflow:- ");
        exit(0);
    }
    stack[++top]=ch;
}
//pop deleted element
char pop(){
    if(top==-1){
        printf("Stack Underflow");
        exit(0);
    }
    return stack[top--];
}
//check stack is empty or not
int isempty(){
    return top==-1;
}
//check balanced or not
int isBalanced(){
    int i=0;
    while(expression[i]!='\0'){
        if(expression[i]=='('||expression[i]=='['||expression[i]=='{'){
            push(expression[i]);
        }
        else if(expression[i]==')'||expression[i]==']'||expression[i]=='}'){
            if(isempty()){
                return 0;
            }
            char topcharacter=pop();
            if(expression[i]==')'&& topcharacter!='('||expression[i]==']'&& topcharacter!='['||expression[i]=='}'&& topcharacter!='{'){
                return 0;
            }
        }
        i++;
    }
    return isempty();
}
int main(){
    printf("Enter the Expression:- ");
    scanf("%[^\n]s",expression);
    if(isBalanced()){
        printf("Expression is balanced");
    }
    else{
        printf("Expression is not Balanced");
    }
    return 0;
}