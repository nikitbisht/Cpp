/*
Qn12:- Write a program in C to check for balanced parentheses in an expression using stack?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define Max_Size 40
char str[Max_Size];
char stack[Max_Size];
int top=-1;

//Add opening bracket into stack
void push(char ch){
    if(top==Max_Size-1){
        printf("Stack Overflow");
        exit(0);
    }
    stack[++top]=ch;
}

//pop out top element from stack
char pop(){
    if(top==-1){
        printf("Stack Underflow");
        exit(0);
    }
    return stack[top--];
}

//check stack empty or not
bool isempty(){
    return top==-1;
}

//Check valid parentheses or not
bool isBalance(){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']'){
            if(isempty()){
                return false;
            }
            char topcharacter=pop();
            if(str[i]==')'&&topcharacter!='(' || str[i]==']'&&topcharacter!='[' || str[i]=='}'&&topcharacter!='{'){
                return false;
            }
        }
        i++;
    }
    return top==-1;		//if(top==-1) then its return 1 else 0
}

int main(){
    int n;
    printf("Enter the String:- ");
    scanf("%[^\n]s",str);
    if(isBalance()){
        printf("Expression is Balanced");
    }
    else{
        printf("Expression is UnBalanced");
    }
    return 0;
}
/*
1.Input:-
Enter the String:- {5*(13-(a/5))}
Output:
Expression is Balanced

2.Input:-
Enter the String:- [{}({[]})]
Output:
Expression is Balanced

3.Input:-
Enter the String:- a(b-c)(){c+d}/]
Output:
Expression is UnBalanced
*/