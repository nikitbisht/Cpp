/*
Qn11:- Write a program in C to implement a stack using a linked list?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*top=0,*temp,*newnode;
//Assume top as head 
int size;
int count=0;
void push(){
    if(count==size){
        printf("Stack Overflow");
    }
    else{
    	// you can see here insertion at head/starting
        count++;
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=top;
        top=newnode;
    }
}
//Delete Linked list element as a way LIFO
void pop(){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else
        top=top->next;
}
// Return peek Element/head element
int peek(){
    if(top==NULL){
        printf("Stack Underflow");
    }
    else{
        return top->data;
    }
}
//to display Linked list
void display(){
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int m;
    printf("Enter the no of element:- ");
    scanf("%d",&size);
    printf("Enter the element :-\n");
    for (int i = 0; i < size; i++){
        push();
    }
    printf("Stack Elements are:- ");
    display();
    printf("\nPeek Element is :- %d",peek());
    printf("\nEnter the no of element you wanna delete:- ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        pop();
    }
    printf("\nAfter delete Stack Elements:- ");
    display();
    return 0;
}