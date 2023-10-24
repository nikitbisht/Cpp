/*
Qn:- Sort 0 1 2 in Linked List
#1 Approch:- count the no of 0,1,2 then replace
#2 Approch:- Changes of Node (data replacement not allowed)
here we are write both approch function
*/
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

//DISPLAY LINKED LIST ELEMENT
void display(node*&head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
//Approch1:- Data Replacement
void Approch1(node*&head){
	node*temp=head;
	int zero=0;
	int one=0;
	int two=0;
	while(temp!=NULL){
		if(temp->data==0){
			zero++;
		}else if(temp->data==1){
			one++;
		}else if(temp->data==2){
			two++;
		}
		temp=temp->next;
	}
	temp=head;
	while(temp!=NULL){
		if(zero!=0){
			temp->data=0;
			zero--;
		}else if(one!=0){
			temp->data=1;
			one--;
		}else if(two!=0){
			temp->data=2;
			two--;
		}
		temp=temp->next;
	}
}
void populate(node*&head,node*&tail){
	head->next=tail;
	head=tail;
}
void Approch2(node*&head){
	node*zerohead=new node(-1);
	node*onehead=new node(-1);
	node*twohead=new node(-1);
	node*zerotail=zerohead;
	node*onetail=onehead;
	node*twotail=twohead;
	node*temp=head;
	while(temp!=NULL){
		if(temp->data==0){
			populate(zerotail,temp);
		}else if(temp->data==1){
			populate(onetail,temp);			
		}else if(temp->data==2){
			populate(twotail,temp);
		}
		temp=temp->next;
	}
	//merge all the linked list
	if(onehead->next!=NULL){
		zerotail->next=onehead->next;
	}else{
		zerotail->next = twohead->next;
	}
	onetail->next=twohead->next;
	head=zerohead->next;
	delete zerohead;
	delete onehead;
	delete twohead;
}
int main(){
	node*head=NULL;
	node*tail=NULL;
	createLinked(head,tail);	
	Approch1(head);
	Approch2(head);
	display(head);
	return 0;
}
