//Linked list reverse by [K-NODE]			#V-imp
#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node*next;
		node(int data) {
			this->data=data;
			this->next=NULL;
		}
};
//Create LINKED LIST
void createLinked(node* &head) {
	int n,a;
	node*tail=NULL;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	cout<<"Enter Linked list Element:- "<<endl;
	for(int i=0; i<n; i++) {
		cin>>a;
		node* newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		} else {
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//display the linked list
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
//Return the size of Linked list
int sizeOfLinked(node*&head){
	int cnt=0;
	node*temp=head;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
node* reverseKnode(node*&head,int k,int size){
	//base case
	if(head==NULL||head->next==NULL){
		return head;
	}
	node*curr=head;
	node*pre=NULL;
	node*forward=NULL;
	for(int i=0;i<k;i++){
		forward=curr->next;
		curr->next=pre;
		pre=curr;
		curr=forward;
		size--;
	}
	if(forward!=NULL&&size>k){
		head->next=reverseKnode(forward,k,size);
	}else{
		head->next=forward;
	}
	return pre;
}
int main() {
	node*head=0;
	int k;
	createLinked(head);
	display(head);
	cout<<"No of time reverse:= "<<endl;
	cin>>k;
	int size=sizeOfLinked(head);
	head=reverseKnode(head,k,size);
	display(head);
	return 0;
} 