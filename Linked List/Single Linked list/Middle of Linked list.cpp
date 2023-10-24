//Middle of Linked List
//TORTOISE AND HARE APPROCH
#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node*next;
		node(int data) {
			this->data=data;
			this->next=NULL;
		}
};
//Create LINKED LIST
void createLinked(node* &head) {
	int n,a;
	node*tail=NULL;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	cout<<"Enter Linked list Element:- "<<endl;
	for(int i=0; i<n; i++) {
		cin>>a;
		node* newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		} else {
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//display the linked list
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int middleLinked(node* &head) {
	node* slow=head;
	node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL) {
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}
int main() {
	node*head=0;
	createLinked(head);
	display(head);
	cout<<"Middle element:- "<<middleLinked(head)<<endl;
	return 0;
}