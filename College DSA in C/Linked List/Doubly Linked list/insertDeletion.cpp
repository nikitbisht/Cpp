#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node* next;
		node* pre;
	public:
		node(int data) {
			this->data=data;
			next=pre=NULL;
		}
};
// 	INSERTION
//AT HEAD
void insertAtHead(node*&head,node*&tail,int data) {
	node*newnode=new node(data);
	if(head==NULL) {
		head=tail=newnode;
	} else {
		newnode->next=head;
		head->pre=newnode;
		head=newnode;
	}
}
//AT END
void insertAtTail(node*&head,node*&tail,int data) {
	node*newnode=new node(data);
	if(tail==NULL) {
		head=tail=newnode;
	} else {
		tail->next=newnode;
		newnode->pre=tail;
		tail=newnode;
	}
}
//ANY POSTITION
void insertAtPostion(node*&head,node*&tail,int posi,int data) {
	if(posi==1) {
		insertAtHead(head,tail,data);
		return ;
	}
	node*temp=head;
	int cnt=1;
	while(cnt<posi-1) {
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL) {
		insertAtTail(head,tail,data);
		return ;
	}
	node*newnode=new node(data);
	temp->next->pre=newnode;
	newnode->next=temp->next;
	newnode->pre=temp;
	temp->next=newnode;
}
//DELETION
void deleteNode(node*&head,node*&tail,int posi){
	if(posi==1){
		node* temp=head;
		temp->next->pre=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	else{
		int cnt=1;
		node*pre=NULL;
		node*cur=head;
		while(cnt<posi){
			pre=cur;
			cur=cur->next;
			cnt++;
		}
		if(cur->next==NULL){
			tail=pre;
		}
		pre->next=cur->next;
		cur->pre=NULL;
		delete cur;
	}
}
// TRAVERSE IN LINKED LIST
void print(node*&head,node*&tail) {
	cout<<"head::- "<<head->data<<endl;
	cout<<"tail::- "<<tail->data<<endl;
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int  main() {
	node*head=NULL;
	node*tail=NULL;
	insertAtHead(head,tail,10);
	print(head,tail);
	insertAtHead(head,tail,9);
	print(head,tail);
	insertAtTail(head,tail,80);
	print(head,tail);
	insertAtPostion(head,tail,1,100);
	print(head,tail);
	insertAtPostion(head,tail,4,15);
	print(head,tail);
	insertAtPostion(head,tail,6,12);
	print(head,tail);
	
	cout<<endl<<"DEletion"<<endl<<endl;
	deleteNode(head,tail,6);
	print(head,tail);
	deleteNode(head,tail,1);
	print(head,tail);
	deleteNode(head,tail,3);
	print(head,tail);
	return 0;
}