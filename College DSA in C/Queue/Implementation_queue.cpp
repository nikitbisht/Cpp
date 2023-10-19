#include<iostream>
using namespace std;
#define Max 10
int front=-1;
int rear=-1;
int arr[Max];
//Add Element
void inqueue(){
    if(rear==Max-1){
        cout<<"Queue Overflow"<<endl;
        return ;
    }
    else{
        if(front==-1)
            front++;
        cin>>arr[++rear];
    }
}
//Delete Element
void dequeue(){
    if(front==-1||front>rear){
        cout<<"Queue Under flow"<<endl;
        return ;
    }
    else{
        front++;
    }
}
//display Queue
void displayQueue(){
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,m;
    cout<<"Size"<<endl;
    cin>>n;
    cout<<"Element"<<endl;
    for(int i=0;i<n;i++){
        inqueue();
    }
    cout<<"No of delete element"<<endl;
    cin>>m;
    displayQueue();
    for(int i=0;i<m;i++){
        dequeue();
    }
    displayQueue();
    cout<<front<<endl;
    cout<<rear<<endl;
}