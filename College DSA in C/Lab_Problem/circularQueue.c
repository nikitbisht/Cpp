/*
Qn7:- Write a program in C to create a circular queue with N elements. Execute and display teh results of functions enqueue() and dequeue() on the circular queue?
*/
#include<stdio.h>
#define Max 10
int queue[Max];
int size;
int front=-1,rear=-1;
void enqueue(){
    if(front==-1){
        front = rear = 0;
        scanf("%d",&queue[rear]);
    }
    else if(front%size==(rear+1)%size){
        printf("Queue is Full");
    }
    else{
        rear=(rear+1)%size;
        scanf("%d",&queue[rear]);
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is Empty");
    }
    else if(front%size==rear%size){
        front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
}

void display(){
    printf("Queue Elements are:- \n");
    int i=front;
    while(i!=rear){
        printf(" %d",queue[i]);
        i=(i+1)%size;
    }
    if(i==rear){
        printf(" %d",queue[i]);
    }
}
int main(){
    int m,j,k;
    printf("Enter the size of Queue:- ");
    scanf("%d",&size);
    printf("Enter the Element in  queue:- ");
    for(int i=1;i<=size;i++){
        enqueue();
    }
    display();
    printf("\n Enter the No of Element you want to delete:- ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        dequeue();
    }
    display();
    printf("\nEnter the no of Element you want to add:-");
    scanf("%d",&j);
    for(int i=0;i<j;i++){
        enqueue();
    }
    display();
    return 0;
}
/*
1.Input:- 
Enter the size of Queue:- 5
Enter the Element in  queue:- 1 2 3 4 5
Queue Elements are:- 
 1 2 3 4 5
Enter the No of Element you want to delete:- 3
Queue Elements are:- 
 4 5
Enter the no of Element you want to add:- 3 
1 2 3
Output:- 
Queue Elements are:- 
 4 5 1 2 3

2.Input:-
Enter the size of Queue:- 8
Enter the Element in  queue:- 9 8 6 2 1 4 5 7
Queue Elements are:- 
 9 8 6 2 1 4 5 7
 Enter the No of Element you want to delete:- 5
Queue Elements are:- 
 4 5 7
Enter the no of Element you want to add:- 1
3
Output:
Queue Elements are:- 
 4 5 7 3

3.Input:-
Enter the size of Queue:- 4
Enter the Element in  queue:- 10 20 30 40
Queue Elements are:- 
 10 20 30 40
Enter the No of Element you want to delete:- 4
Queue Elements are:- 
0
Enter the no of Element you want to add:-2
10 60
Output:-
Queue Elements are:- 
 10 60
*/