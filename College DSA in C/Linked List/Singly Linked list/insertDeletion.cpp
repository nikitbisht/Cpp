#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		
	Node(int data){
		this->data=data;
		next=NULL;
	}
};
// INSEART AT HEAD
void insertAtHead(Node* &head,Node*&tail,int data){
	Node*newnode=new Node(data);
	if(head==NULL){
		head=newnode;
		tail=newnode;
	}
	else{
		newnode->next=head;
		head=newnode;
	}
}
// INSERT AT TAIL
void insertAtTail(Node*&head,Node* &tail,int data){
	Node*newnode=new Node(data);
	if(tail==NULL){
		head=tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
}
// INSET AT ANY POSITION
void insertAtPosition(Node* &head,Node* &tail,int position,int data){
	if(position==1){
		insertAtHead(head,tail,data);
		return ;
	}
	else{
		int cnt=0;
		Node*temp=head;
		while(cnt<position-1){
			temp=temp->next;
			cnt++;
		}
		Node*newnode=new Node(data);
		// Last position
		if(temp->next==NULL){
			insertAtTail(head,tail,data);
			return ;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
//Deletion in lineked list
void deleteNode(Node* &head,Node*&tail,int position){
	if(position==1){
		head=head->next;
	}
	else{
		int cnt=1;
		Node* pre=NULL;
		Node* cur=head;
		while(cnt<position){
			pre=cur;
			cur=cur->next;
			cnt++;
		}
		if(cur->next==NULL){
			tail=pre;
		}
		pre->next=cur->next;
	}
}
void print(Node*&head,Node*&tail){
	cout<<"head::- "<<head->data<<endl;
	cout<<"tail::- "<<tail->data<<endl;
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* head =NULL;
	Node* tail = NULL;
	insertAtHead(head,tail,12);
	print(head,tail);
	insertAtPosition(head,tail,1,6);
	print(head,tail);
	insertAtPosition(head,tail,2,45);
	print(head,tail);
	insertAtPosition(head,tail,3,78);
	print(head,tail);
	insertAtTail(head,tail,5);
	print(head,tail);
	
	cout<<"\n Deletion"<<endl;

	deleteNode(head,tail,5);
		print(head,tail);

	deleteNode(head,tail,1);
	print(head,tail);

	deleteNode(head,tail,2);
	print(head,tail);

	
	
	return 0;
}