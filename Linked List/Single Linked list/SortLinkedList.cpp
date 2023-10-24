//Sort a Linked List
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
void display(node*head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void sortL(node* &head){
	if(head==NULL||head->next==NULL){
		return ;		//return NULL
	}
	node*temp=head;
	node*pre=head;
	node*cur=head;
	while(temp->next!=NULL){
		pre=head;
		cur=head->next;
		while(cur!=NULL){
			if(pre->data>cur->data){
				int x=pre->data;
				pre->data=cur->data;
				cur->data=x;
			}
			pre=pre->next;
			cur=cur->next;
		}
		temp=temp->next;
	}
}
int main(){
	int n;
	cout<<"Enter the size of LL"<<endl;
	cin>>n;
	node *head=0,*temp=0,*newnode=0;
	for(int i=0;i<n;i++){
		newnode=new node;
		newnode->next=0;
		cin>>newnode->data;
		if(head==0){
			head=temp=newnode;
		}else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	display(head);
	sortL(head);
	display(head);
	return 0;
}