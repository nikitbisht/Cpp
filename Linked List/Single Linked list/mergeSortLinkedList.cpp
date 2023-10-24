//Merge Sort in Linked list
/*
T.C:- O(n*log(n))
S.C:- O(Log(n))
*/
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
void display(node*&head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insertAtTail(node*&head,node*&tail,int val) {
	node* newnode=new node(val);
	if(head==NULL) {
		head=tail=newnode;
	} else {
		tail->next=newnode;
		tail=newnode;
	}
}
//Find mid
node* getMid(node* &head){
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL && fast->next!=NULL) {
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
//merge Linked list
node* mergeLinked(node*&left,node*&right) {
	if(left==NULL) {
		return right;
	}
	if(right==NULL) {
		return left;
	}
	if(left->next==NULL) {
		left->next=right;
		return left;
	}
	node*first=left;
	node*next=left->next;
	node* second=right;
	while(next!=NULL&&second!=NULL) {
		if(second->data>=first->data&&second->data<=next->data) {
			first->next=second;
			node*temp=second->next;
			second->next=next;

			first=first->next;
			second=temp;
		} else {
			first=first->next;
			next=next->next;
			if(next==NULL) {
				first->next=second;
				return left;
			}
		}
	}
	return left;
}
//Merge Sort
node* mergeSort(node*&head) {
	//base case
	if(head==NULL||head->next==NULL) {
		return head;
	}
	//Step1:- find mid
	node* mid=getMid(head);
	//Step2:- Break LL in to 2 halfs
	node*left=head;
	node*right=mid->next;
	mid->next=NULL;
	//Step3:- Sort Recursion for both side
	left=mergeSort(left);

	right=mergeSort(right);

	//Step4:- Merge left/right sorted halves
	if(left->data<=right->data) {
		return mergeLinked(left,right);
	}
	else{
		return mergeLinked(right,left);
	}
}
int main() {
	int n;
	node*head=NULL;
	node*tail=NULL;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		insertAtTail(head,tail,a);
	}
	display(head);
	head=mergeSort(head);
	display(head);
	return 0;
}