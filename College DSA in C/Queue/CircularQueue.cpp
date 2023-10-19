#include<iostream>
using namespace std;
#define Max 10
int n;
int arr[Max];
int front=-1;
int rear = -1;
void enQueue(){
    if(front==-1){
        front=0;
        rear=0;
      cin>>arr[rear];
    }
    else if(front%n==(rear+1)%n){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear=(rear+1)%n;
        cin>>arr[rear];
    }
}
void displayQueue(){
    int i=front;
    while(i!=rear){
        cout<<arr[i]<<" ";
        i=(i+1)%n;
    }
    if(i==rear)
        cout<<arr[i]<<endl;
}
void deQueue(){
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    if(front%n==rear%n){
        rear=-1;
        front=-1;
    }
    else{
        front=(front+1)%n;
    }
}
int main(){
    cin>>n;
    cout<<"Queue Element:- "<<endl;
    for(int i=0;i<n;i++){
        enQueue();
    }
    cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<rear<<endl;
    displayQueue();
    int m;
    cout<<"No of element you wanna delete:- "<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        deQueue();
    }
      cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<rear<<endl;
    displayQueue();
    int k,j;
    cin>>k;
    for(int i=0;i<k;i++){
        enQueue();
    }
      cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<rear<<endl;
    displayQueue();
    cin>>j;
    for(int i=0;i<j;i++){
        deQueue();
    }
    displayQueue();
    cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<rear<<endl;
    return 0;
}