// Reverse Linked List using Recursion
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
void display(node* temp){
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	delete temp;
}
node* reverse(node*head){
	//base case
	if(head==NULL||head->next==NULL){
		return head;
	}
	node*h2=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return h2;
}
int main(){
	node*head=0;
	node*temp;
	node*newnode;
	int n;
	cout<<"Enter the size of Linked List:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		newnode=new node;
		newnode->next=0;
		cin>>newnode->data;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}
//	display(head);
	head=reverse(head);
	display(head);
	return 0;
}