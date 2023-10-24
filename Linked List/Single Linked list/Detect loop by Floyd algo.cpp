/*
Detect a Loop From the Linked list
Approch 1:- Use Map data Structure
Approch 2:- Floyd's cycle detection Algorith
*/
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
void createLinked(node* &head,node*&tail) {
	int n,a;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	cout<<"Enter Linked list Element:- "<<endl;
	for(int i=0; i<n; i++) {
		cin>>a;
		node* newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//display the linked list
void display(node* &head) {
	cout<<"Linked list Elements :- "<<endl;
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
bool flyodCycleDetection(node*&head) {
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast){
			return true;
		}
	}
	return false;
}
int main() {
	node*head=0; 
	node*tail=0;
	createLinked(head,tail);
	display(head);
/*
	we just create a single ll and the below line is to make a loop in it and if you want to check it is
	has loop then u can run display fn after & it never stop.
*/	tail->next=head->next;
	if(flyodCycleDetection(head)){	
		cout<<"Linked List has a Loop"<<endl;
	} else {
		cout<<"Linked List does not have Loop"<<endl;
	}
	return 0;
}