// to be continued
#include<stdio.h>
#define max 30
int queue1[max];
int queue2[max];
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
void enqueue1(int data){
    if(rear1==max-1){
        printf("Queue1 is Full");
        return ;
    }
    else if(front1==-1){
        front1=0;
        rear1=rear1+1;
        queue1[rear1]=data;
    }
    else{
        queue1[++rear1]=data;
    }
}
void enqueue2(int data){
    if(rear2==max-1){
        printf("Queue2 is Full");
        return ;
    }
    else if(front2==-1){
        front2=0;
        rear2=rear2+1;
        queue2[rear2]=data;
    }
    else{
        queue2[++rear2]=data;
    }
}

//dequeue
int  dequeue1(){
    if(front1==-1||front1>rear1){
        printf("Queue is Empty");
    }
    else{
        return queue1[front1++];
    }
}
int  dequeue2(){
    if(front2==-1||front2>rear2){
        printf("Queue is Empty");
    }
    else{
        return queue2[front2++];
    }
}
//Call enqueue fn
void push(int x){
    enqueue2(x);
    while(front1<=rear1){
        int a=dequeue1();
        enqueue2(a);
    }
    front1=rear1=-1;
    while(front2<=rear2){
        int a=dequeue2();
        enqueue1(a);
    }
    front2=rear2=-1;
}

void display(){
    for(int i=front1;i<=rear1;i++){
        printf("%d ",queue1[i]);
    }
}
int main(){
    int n,a,m;
    printf("Enter the no of element you want to add in stack:- ");
    scanf("%d",&n);
    printf("Enter the stack Element:- ");
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        push(a);
    }
    display();
    return 0;
}