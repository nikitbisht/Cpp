/*
Qn:- REMOVE DUPLICATE FROM UNSORTED LIST
Method:
	1. Sort the Linked list
	2. delete duplicate in sorted algo
T.C:- O(nlog(n))
S.C:- O(log(n))
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
void createLinked(node*&head){
	int n,a;
		node*tail=NULL;
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

//FIND MID
node* getMid(node*&head){
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

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

node* mergeSort(node*&head){
	//base case
	if(head==NULL||head->next==NULL){
		return head;
	}
	//Step1:- Fing mid and seprate both path
	node*mid=getMid(head);
	node*left=head;
	node*right=mid->next;
	mid->next=NULL;
	left=mergeSort(left);
	right=mergeSort(right);
	//merge sorted LL
	return mergeLinked(left,right);
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
	createLinked(head);	
	head = mergeSort(head);
	removeDuplicate(head);
	display(head);
	return 0;
}
