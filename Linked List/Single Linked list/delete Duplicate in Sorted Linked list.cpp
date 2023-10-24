//REMOVE DUBLICATE ELEMENT FORM SORTED LINKED LIST
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
//REMOVE DUPLICATE FROM SORTED LINKED LIST
void removeDuplicate(node*&head){
	node*temp=head;
	while(temp!=NULL&&temp->next!=NULL){
		if(temp->data==temp->next->data){
			temp->next=temp->next->next;
		}else{
			temp=temp->next;
		}
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
	node*head=NULL;
	node*tail=NULL;
	createLinked(head,tail);	
	display(head);
	removeDuplicate(head);
	display(head);
	return 0;
}