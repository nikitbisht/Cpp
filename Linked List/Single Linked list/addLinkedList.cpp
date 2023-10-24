//Add 2 Number in LL
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
void insertatTail(node*&head,node*&tail,int val) {
	node*newnode=new node(val);
	if(head==NULL) {
		head=tail=newnode;
	} else {
		tail->next=newnode;
		tail=newnode;
	}
}

node* reverse(node* &head) {
	node*curr=head;
	node*pre=NULL;
	node*next=NULL;
	while(curr!=NULL) {
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
	}
	return pre;
}

node* addLinked(node* &head1,node* &head2) {
	node* anshead=NULL;
	node* anstail=NULL;
	//Step1:- Reverse LL
	node* temp1=reverse(head1);
	node* temp2=reverse(head2);
	int sum=0,carry=0,digit=0;
	while(temp1!=NULL||temp2!=NULL||carry!=0) {
		int val1=0,val2=0;
		if(temp1!=NULL){
			val1=temp1->data;
		}
		if(temp2!=NULL){
			val2=temp2->data;
		}
		sum=val1+val2+carry;
		digit=sum%10;
		carry=sum/10;
		//insert in new LL
		insertatTail(anshead,anstail,digit);
		if(temp1!=NULL) {
			temp1=temp1->next;
		}
		if(temp2!=NULL) {
			temp2=temp2->next;
		}
	}
	return reverse(anshead);
}
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}
int main() {
	node*head1=0,*head2=0;
	createLinked(head1);
	createLinked(head2);
	node*head = addLinked(head1,head2);
	display(head);
	return 0;
}