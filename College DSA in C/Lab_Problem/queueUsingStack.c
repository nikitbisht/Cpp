/*
Qn8:- Write a program in C to implement a queue using stack?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 10
int stack1[Max_Size];
int stack2[Max_Size];
int top1=-1,top2=-1;
int size;

//Return Element from Stack-1
int pop1(){
    if(top1==-1){
        printf("Queue is empty");
        exit(1);
    }
    return stack1[top1--];
}
//Push Element in Stack-2
void push2(int data){
    if(top2==size-1){
        printf("Queue is full");
        return ;
    }
    else{
        stack2[++top2]=data;
    }
}
//Push Element into Stack-1
void push1(int data){
    if(top1==size-1){
        printf("Queue is full");
        return ;
    }
    else{
        stack1[++top1]=data;
    }
}
//Return Element from Stack-2
int pop2(){
    if(top2==-1){
        printf("Queue is empty");
        exit(1);
    }
    else{
        return stack2[top2--];
    }
}
//Add Element into Queue
void enqueue(int x){
    while(top1!=-1){        //stack1 to stack2
        int x = pop1();
        push2(x);
    }
    stack1[++top1]=x;       //data in stack1
    while (top2!=-1){
        int x=pop2();
        push1(x);
    }
}
//Return top Element from Queue
int peek(){
    return stack1[top1];
}
//Delete Queue Element
void dequeue(){
    if(top1==-1){
        printf("Queue is empty");
        exit(1);
    }
    else{
        top1--;
    }
}
//Display Queue
void display(){
    printf("Queue Elements are:- \n");
    for (int  i = top1; i >=0; i--){
        printf("%d ",stack1[i]);
    }
}
int main(){
    int m;
    printf("Enter the size of queue:- ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        int a;
        scanf("%d",&a);
        enqueue(a);
    }
    display();
    printf("\nPeek Element is :- %d",peek());
    printf("\nEnter the no of element you want to delete:- ");
    scanf("%d",&m);
    
    for(int i=0;i<m;i++){
        dequeue();
    }
    printf("\nAfter Deletion ");
    display();
}