//Bubble Sort in Linked list
//here we are doing data replacement method
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};
//CREATE LINKED LIST
void createLinked(node*&head,node*&tail){
	int n,a;
	cout<<"Enter the size of Linked list:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		node* newnode=new node(a);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}else{
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//Bubble sort:- set the maximum element at the end
void bubbleSort(node*&head){
	node*curr=NULL;
	node*temp=head;
	while(temp!=NULL){
		curr=head;
		while(curr!=NULL&&curr->next!=NULL){
			if(curr->data>curr->next->data){
				swap(curr->data,curr->next->data);
			}
			curr=curr->next;
		}
		temp=temp->next;
	}
}
//DISPLAY LINKED LIST ELEMENT
void display(node*&head){
	cout<<"Linked List Element:- "<<endl;
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	node*head=NULL;
	node*tail=NULL;
	createLinked(head,tail);	
	display(head);
	cout<<"After BUBBLE sort"<<endl;
	bubbleSort(head);
	display(head);
	return 0;
}