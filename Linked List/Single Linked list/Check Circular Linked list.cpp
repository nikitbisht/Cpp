/*
Check Circular Linked list
Approch:-
1. Tortoise and hare approch
2. Mapping use map(ghatiya approch S.C:- O(N))
3. Traversing in loop until head not come
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
//Create LINKED LIST
void createLinked(node* &head,node*&tail) {
	int n,a;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	cout<<"Enter Linked list Element:- "<<endl;
	for(int i=0; i<n; i++) {
		cin>>a;
		node* newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	}
}
//display the linked list
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
bool isCircular(node*&head) {
	node*temp=head->next;
	while(temp!=head&&temp!=NULL) {
		temp=temp->next;
	}
	if(temp) {
		return true;
	}else{
		return false;
	}
}
int main() {
	node*head=0; 
	node*tail=0;
	createLinked(head,tail);
	display(head);
/*
	we just create a single ll and the below line is to make it cirular ll and if you want to check it is
	circular then u can run display fn after & it never stop.
*/	tail->next=head;
	if(isCircular(head)){	
		cout<<"Circular Linked List"<<endl;
	} else {
		cout<<"Not a Circular Linked List"<<endl;
	}
	return 0;
}