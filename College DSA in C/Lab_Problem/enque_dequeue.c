/*
Qn13:- Write a program in C to enqueue n element in queue and dequeue n element from a queue?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 20
int queue[Max_Size];
int front = -1;
int rear = -1;
//Add element in queue
void enqueue(int data){
    if(rear==Max_Size-1){
        printf("Stack Overflow");
        exit(0);
    }
    if(front==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else{
        queue[++rear]=data;
    }
}
//Delete queue element
void dequeue(){
    if(front==-1||front>rear){
        printf("Stack Underflow");
        exit(0);
    }
    front++;
}
//display queue
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main(){
    int n,m;
    printf("Enter the Size of Queue:- ");
    scanf("%d",&n);
    printf("Enter Queue Elements:- \n");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Enter the no of element you want to delete from Queue:- ");
    scanf("%d",&m);
    printf("Queue Elements :- \n");
    display();
    for(int i=0;i<m;i++){
        dequeue();
    }
    printf("\nAfter Deleting Queue Elements:- \n");
    display();
    return 0;
}
/*
1.Input:-
Enter the Size of Queue:- 5
Enter Queue Elementn
1 2 3 4 5
Enter the no of element you want to delete from Queue:- 3
Output:
Queue Elements :- 
1 2 3 4 5 
After Deleting Queue Elements:- 
4 5 

2.Input:- 
Enter the Size of Queue:- 8
Enter Queue Elements:-
9 8 6 5 1 2 3 4
Enter the no of element you want to delete from Queue:- 5
Output:
Queue Elements :-
9 8 6 5 1 2 3 4
After Deleting Queue Elements:-
2 3 4

3.Input:- 
Enter the Size of Queue:- 4
Enter Queue Elements:-
10 20 30 40
Enter the no of element you want to delete from Queue:- 1
Output:
Queue Elements :-
10 20 30 40
After Deleting Queue Elements:-
20 30 40
*/