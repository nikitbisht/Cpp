/*
Qn7:- Write a program in C to implement push() and pop() operation in stack using array?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 10

//Add Element into Stack
void push(int *stack,int *top,int size){
    if(*top==size-1){
        printf("Stack OverFlow\n");
        return ;
    }
    int data;
    scanf("%d",&data);
    stack[++(*top)]=data;
}

//Delete Element from stack
void pop(int *top){
    if(*top==-1){
        printf("Stack UnderFlow\n");
        exit(0);
    }
    (*top)--;
}

//Display Stack Element
void display(int *stack,int top){
    while(top!=-1){
        printf("%d ",stack[top]);
        top--;
    }
}
int main(){
    int size,n;
    int top=-1;
    int stack[Max_Size];
    printf("Enter the Size of stack:- ");
    scanf("%d",&size);
    printf("Enter the Stack Element:- ");
    for (int i = 0; i < size; i++){
        push(stack,&top,size);
    }
    printf("Enter the no of Element you want to delete form stack:- ");
    scanf("%d",&n);
    
    printf("Stack Elemet are:- \n");
    display(stack,top);
    
    for (int i = 0; i < n; i++){
        pop(&top);
    }
    printf("\nAfter Deleting Stack Element:- \n");
    display(stack,top);
    return 0;
}
/*
1.Input:-
Enter the Size of stack:- 5
Enter the Stack Element:- 1 2 3 4 5
Enter the no of Element you want to delete form stack:- 3
Output:
Stack Elemet are:- 
5 4 3 2 1 
After Deleting Stack Element:- 
2 1 

2.Input:-
Enter the Size of stack:- 8
Enter the Stack Element:- 8 7 6 5 4 3 2 1
Enter the no of Element you want to delete form stack:- 5
Output:
Stack Elemet are:- 
1 2 3 4 5 6 7 8 
After Deleting Stack Element:- 
6 7 8 

3.Input:- 
Enter the Size of stack:- 6
Enter the Stack Element:- 8 9 7 4 1 0 
Enter the no of Element you want to delete form stack:- 2
Output:
Stack Elemet are:- 
0 1 4 7 9 8 
After Deleting Stack Element:- 
4 7 9 8 
*/