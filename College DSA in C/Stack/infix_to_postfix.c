#include<stdio.h>
#define Max_Size 40
char stack[Max_Size];
char str[Max_Size];
int top=-1;
//check operand
int operand(char ch){
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='1'&&ch<='9'){
        return 1;
    }
    else
        return 0;
}
//push into stack
void push(char ch){
    if(top==Max_Size-1){
        printf("stack overflow\n");
        return ;
    }
    stack[++top]=ch;
}
//return deleted element form stack
char pop(){
    if(top==-1){
        printf("Stack underflow");
        return -1;
    }
    char ch=stack[top];
    top--;
    return ch;
}
//return top element from the stack
char peek(){
    return stack[top];
}
int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    else{    
        return -1;
    }
}
void infix_to_postfix(){
    int curIndex=0;
    while(str[curIndex]!='\0'){
        if(operand(str[curIndex])){
            printf("%c",str[curIndex]);
        }
        else if(str[curIndex]=='('){
            push(str[curIndex]);
        }
        else if(str[curIndex]==')'){
            while(peek()!='('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(precedence(peek())>=precedence(str[curIndex])){
                printf("%c",pop());
            }
            push(str[curIndex]);
        }
        curIndex++;
    }
    while(top!=-1)
        printf("%c",pop());
}
int main(){
    scanf("%[^\n]s",str);
    infix_to_postfix();
}