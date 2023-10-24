//Merge 2 Sorted Linked list
// Float like a Cadillac...
// Sting like a Beemer!
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
void createLinked(node* &head) {
	int n,a;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	node*tail;
	for(int i=0; i<n; i++) {
		cin>>a;
		node*newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		} else {
			tail->next=newnode;
			tail=newnode;
		}
	}
}
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
node* mergeLinked(node*&,node*&);
int main() {
	node*head1=NULL,*head2=NULL;
	node* head;
	createLinked(head1);
	createLinked(head2);
	if(head1->data<=head2->data) {
		head = mergeLinked(head1,head2);
	} else {
		head = mergeLinked(head2,head1);
	}
	display(head);
	return 0;
}
node* mergeLinked(node*&head1,node*&head2) {
	// check some edge cases
	if(head1==NULL) {
		return head2;
	}
	if(head1->next==NULL) {
		head1->next=head2;
		return head1;
	}
	if(head2==NULL) {
		return head1;
	}
	node* temp1=head1;
	node* temp2=head2;
	node* next=head1->next;
	node* temp=NULL;
	while(next!=NULL&&temp2!=NULL) {
		if(temp2->data>=temp1->data&&temp2->data<=next->data) {
			//Setup of element
			temp1->next=temp2;
			temp=temp2->next;
			temp2->next=next;
			//update
			temp1=temp1->next;
			temp2=temp;
		} else {
			temp1=temp1->next;
			next=next->next;
			// if next is reach NULL but still ll 2 have element
			if(next==NULL) {
				temp1->next=temp2;
				return head1;
			}
		}
	}
	return head1;
}








