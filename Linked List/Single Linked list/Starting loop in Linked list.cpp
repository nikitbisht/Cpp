/*
work in progress

Find out the starting point of the Loop:
method:-
	step1:- through flyod algo find out the intersection node
	step2:- set slow to head
	step3:- while(slow!=intersection) run
	step4:-  return slow (it will be you starting loop point)
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
		} else {
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//display the linked list
void display(node* &head) {
	cout<<"Linked list Elements :- "<<endl;
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
node* flyodCycleDetection(node*&head) {
	node*slow=head;
	node*fast=head;
	while(fast!=NULL && slow!=NULL) {
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		if(slow==fast) {
			return slow;
		}
	}
	return NULL;
}
node* getstaring(node* &head) {
	node*slow=head;
	node*intersection=flyodCycleDetection(head);
	while(slow != intersection) {
		slow=slow->next;
		intersection=intersection->next;
	}
	return slow;
}
int main() {
	node*head=0;
	node*tail=0;
	createLinked(head,tail);
	display(head);
	/*
		we just create a single ll and the below line is to make a loop in it and if you want to check it is
		has loop then u can run display fn after & it never stop.
	*/
	tail->next=head->next;
	if(!flyodCycleDetection(head)) {
		return 0;
	}
	node*temp= getstaring(head);
	cout<<temp->data<<endl;
	return 0;
}