// Reverse Linked List using Recursion
#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node* next;
};
node* deleted(node*head,int val) {
	node*temp=head;
//	node*cur=head;
	node*pre=NULL;
	while(temp!=NULL) {
		if(temp->data==val) {
			if(temp==head) {
				head=head->next;
			} else {
				pre->next=temp->next;
			}
		}
		pre=cur;
		cur=cur->next;
		temp=temp->next;
	}
	return head;
}
void display(node* temp) {
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	delete temp;
}
int main() {
	node*head=0;
	node*temp;
	node*newnode;
	int n;
	cout<<"Enter the size of Linked List:- "<<endl;
	cin>>n;
	for(int i=0; i<n; i++) {
		newnode=new node;
		newnode->next=0;
		cin>>newnode->data;
		if(head==0) {
			head=temp=newnode;
		} else {
			temp->next=newnode;
			temp=newnode;
		}
	}
	cout<<"before"<<endl;
	display(head);
	int val=7;
	head=deleted(head,val);
	cout<<"after"<<endl;
	display(head);
	return 0;
}