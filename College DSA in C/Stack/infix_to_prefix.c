#include<stdio.h>
#include<string.h>
#define Max_Size 40
char stack[Max_Size];
char expression[Max_Size];
char ans[Max_Size];
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
void infix_to_prefix(){
    int curIndex=0,i=0;
    while(expression[curIndex]!='\0'){
        if(operand(expression[curIndex])){
           ans[i++]=expression[curIndex];
        }
        else if(expression[curIndex]=='('){
            push(expression[curIndex]);
        }
        else if(expression[curIndex]==')'){
            while(peek()!='('){
                ans[i++]=pop();
            }
            pop();
        }
        else{
            while(precedence(peek())>=precedence(expression[curIndex])){
                ans[i++]=pop();
            }
            push(expression[curIndex]);
        }
        curIndex++;
    }
    while(top!=-1)
       ans[i++]=pop();
}
//Reverse string
void reverse(char s1[]){
    int i=0;
    int j=strlen(s1)-1;
    while(i<j){
        char temp = s1[i];
        s1[i++]=s1[j];
        s1[j--]=temp;
    }
}
//invert bracket
void invertBrackert(){
    for(int i=0;i<strlen(expression);i++){
        if(expression[i]==')'){
            expression[i]='(';
        }
        else if(expression[i]=='('){
            expression[i]=')';
        }
    }
}
int main(){
    scanf("%[^\n]s",expression);
    reverse(expression);    
    // puts(expression);
    invertBrackert();
    infix_to_prefix();
    puts(ans);
    reverse(ans);
    puts(ans);
}