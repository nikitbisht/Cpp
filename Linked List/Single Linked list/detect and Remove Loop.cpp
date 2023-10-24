//Remove cycle from loop
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
//FLYOD'S CYCLE DECTECTION ALGORITHM
node* flyodCycleDetection(node*&head){
	if(head==NULL||head->next==NULL){
		return NULL;
	}
	node*slow=head;
	node*fast=head;
	while(slow!=NULL&&fast!=NULL){
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		if(slow==fast){
			return slow;
		}
	}
	return NULL;
}
//FIND THE STARTING POINT OF LINKED LIST
node* gettingStart(node*&head){
	node* intersection=flyodCycleDetection(head);
	if(intersection==NULL){
		return NULL;
	}
	node* slow=head;
	while(slow!=intersection){
		slow=slow->next;
		intersection=intersection->next;
	}
	return slow;
}
//REMOVE THE LOOP FROM lINKED LIST
void removeLoop(node*&head){
	if(head==NULL){
		return ;
	}
	node* start=gettingStart(head);
	if(start==NULL){
		return ;
	}
	node* temp=start->next;
	while(temp->next!=start){
		temp=temp->next;
	}
	temp->next=NULL;
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
	node*head=NULL;
	node*tail=NULL;
	createLinked(head,tail);	
	display(head);
	tail->next=head->next;
	if(flyodCycleDetection(head)==NULL){
		return 0;
	}
	removeLoop(head);
	display(head);
	return 0;
}