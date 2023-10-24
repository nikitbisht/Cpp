//Check Pralimdrome
#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node* next;
		node(int data) {
			this->data=data;
			this->next=NULL;
		}
};
void display(node* &head) {
	node*temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
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
node* getMid(node* &head) {
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL) {
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
bool isPalindrome(node* &head) {
	//Step1:- Find Mid
	node*mid= getMid(head);
	//Step2:- Reverse after mid
	mid->next=reverse(mid->next);
	//Step3:- Comparesion
	node*head1 = head;
	node*head2 = mid->next;
	while(head2!=NULL) {
		if(head1->data!=head2->data) {
			//Step4:- Now again restore your LL
			mid->next=reverse(mid->next);
			return false;
		}
		head1=head1->next;
		head2=head2->next;
	}
	//Step4:- Now again restore your LL
	mid->next=reverse(mid->next);
	return true;
}
int main() {
	int n,a;
	node* head = NULL,*tail;
	node* newnode = NULL;
	cout<<"Enter the size of LL:- "<<endl;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a;
		newnode=new node(a);
		if(head==NULL) {
			head=tail=newnode;
		} else {
			tail->next=newnode;
			tail=newnode;
		}
	}
//	display(head);
	if(isPalindrome(head)) {
		cout<<"Palindrome"<<endl;
	} else {
		cout<<"Not Palindrome"<<endl;
	}
	display(head);
	return 0;
}