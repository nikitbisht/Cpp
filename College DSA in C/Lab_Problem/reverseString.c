/*
Qn8:- Write a program in C to print the reverse of a string using stack?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#define Max_Size 40
void push(char ch,int*top,char *stack){
    if(*top==Max_Size-1){
        printf("Stack Overflow");
        return ;
    }
    stack[++(*top)]=ch;
}
char pop(char *stack,int *top){
    if(*top==-1){
        printf("Stack UnderFlow");
    }
    return stack[(*top)--];
}
int main(){
    char str[Max_Size];
    char stack[Max_Size];
    int top=-1;
    int i=0;
    printf("Enter the String:- \n");
    scanf("%[^\n]s",str);
    while(str[i]!='\0'){
         push(str[i],&top,stack);
         i++;
    }
    i=0;
    while(top!=-1){
        str[i++]=pop(stack,&top);
    }
    printf("\nReverse String:- \n");
    puts(str);
    return 0;
}
/*
1.Input:-
Enter the String:-
Graphic Era Hill University
Output:
Reverse String:- 
ytisrevinU lliH arE cihparG

2.Input:-
Enter the String:- 
Hello Word
Output:
Reverse String:- 
droW olleH

3.Input:-
Enter the String:- 
Uttarakhand
Output:
Reverse String:-
dnahkarattU
*/