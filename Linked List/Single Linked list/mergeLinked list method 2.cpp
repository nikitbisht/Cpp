//Merge 2 Linked list:- Method 2
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
void createLinked(node*&head){
	int n,a;
	node* tail;
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
//Merge 2 Linked list
node* mergeLinked(node*&head1,node*&head2){
	
	node*first=head1;
	node*second=head2;
	node*next=head1->next;
	node*mainhead = new node(0);
	node*maintail=mainhead;
	while(first!=NULL&&second!=NULL){
		if(first->data<second->data){
			maintail->next=first;
			maintail=first;
			first=first->next;
		}else{
			maintail->next=second;
			maintail=second;
			second=second->next;
		}
	}
	while(first!=NULL){
		maintail->next=first;
		maintail=first;
		first=first->next;
	}
	while(second!=NULL){
		maintail->next=second;
		maintail=second;
		second=second->next;
	}
	head1=mainhead->next;
	delete mainhead;
	return head1;
	
}
//DISPLAY LINKED LIST ELEMENT
void display(node*&head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	node*head1=NULL;
	node*head2=NULL;
	createLinked(head1);	
	createLinked(head2);	
	node*head=mergeLinked(head1,head2);
	display(head);
	return 0;
}