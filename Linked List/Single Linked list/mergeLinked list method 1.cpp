//Merge 2 Linked list:- Method:- 1
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
	if(head1->next==NULL){
		head1->next=head2;
		return head1;
	}
	node*first=head1;
	node*second=head2;
	node*next=head1->next;
	while(next!=NULL&&second!=NULL){
		if(second->data>=first->data&&second->data<=next->data){
			node*temp=second->next;
			first->next=second;
			second->next=next;
			//updata
			second=temp;
			first=first->next;
		}else{
			first=first->next;
			next=next->next;
			if(next==NULL){
				first->next=second;
				return head1;
			}
		}
	}
	return head1;
	
}
node*solve(node*& head1,node*& head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	if(head1->data<head2->data){
		return mergeLinked(head1,head2);
	}else{
		return mergeLinked(head2,head1);
	}
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
	node*head=solve(head1,head2);
	display(head);
	return 0;
}