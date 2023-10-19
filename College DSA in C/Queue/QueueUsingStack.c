#include<stdio.h>
#define max 10
int stack1[max];
int stack2[max];
int top1=-1,top2=-1;
//Push element in stack 1
void push1(int data){
    if(top1==max-1){
        printf("Stack Overflow");
    }
    else{
        stack1[++top1]=data;
    }
}
//Push element in stack 2
void push2(int data){
    if(top2==max-1){
        printf("Stack Overflow");
    }
    else{
        stack2[++top2]=data;
    }
}
//stack 1
void enqueue(int x){
    push1(x);
}
//return element from stack1
int pop1(){
    return stack1[top1--];
}
//return element from stack2
int pop2(){
    return stack2[top2--];
}
//Deleting queue element
void dequeue(int n){
    if(top1==-1&&top2==-1){
        printf("Queue is empty ");
    }
    else{
        while(top1!=-1){
            push2(pop1());
        }
        for(int i=0;i<n;i++){
            pop2();
        }
        while (top2!=-1){
            push1(pop2());
        } 
    }
}
//display queue
void display(){
    for (int i = 0; i <= top1; i++){
        printf("%d ",stack1[i]);
    } 
}
int main(){
    int n,a,m;
    printf("Enter no of element in stack:- ");
    scanf("%d",&n);
    printf("Enter the element:- ");
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        enqueue(a);
    }
    display();
    printf("Enter the element you wanna delete:- ");
    scanf("%d",&m);
    dequeue(m);
    display();
    return 0;
}