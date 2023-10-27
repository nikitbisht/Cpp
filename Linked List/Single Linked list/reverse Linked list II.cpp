/*
Qn:- Reverse Linked List II
given a linked list and a left and right variable, just reverse the linked list from left index to right index
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
node* reverse(node*&head){
	node*curr=head;
	node*pre=NULL;
	node*next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
	}
	return pre;
}
node* reverseList(node*&head,int left,int right){
	if(head==NULL||head->next==NULL||left==right){
		return head;
	}
	node*head1=NULL;
	node*headtail=NULL;
	node*tail=NULL;
	node*pre=NULL;
	node*curr=head;
	int i=1;
	while(i<=right){
		if(i==left){
			headtail=pre;
			head1=curr;
			if(pre!=NULL){
				headtail->next=NULL;
			}
		}
		else if(i==right){
			tail=curr->next;
			curr->next=NULL;
		}
		i++;
		pre=curr;
		curr=curr->next;
	}
	//Special Case left==1
	if(left==1){
		headtail=reverse(head);
		head1->next=tail;
		return headtail;
	}else{
		headtail->next=reverse(head1);
		head1->next=tail;
		return head;
	}
}
void display(node* &head){
	cout<<"Linked list Elements:- "<<endl;
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	int n,a;
	node* head=NULL;
	node*temp=NULL;
	node*newnode=NULL;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	cout<<"Enter the LL Element:- "<<endl;
	for(int i=0;i<n;i++){
		cin>>a;
		newnode=new node(a);
		if(head==NULL){
			head=temp=newnode;
		}else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	int left,right;
	display(head);
	cout<<"Enter the left and right index:- "<<endl;
	cin>>left>>right;
	head=reverseList(head,left,right);
	cout<<"After reversing form "<<left<<" node to "<<right<<" node"<<endl;
	display(head);
	return 0;
}
