#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	//Constructor
	node(int data){
		this->data = data;
		next = NULL;
	}
};
bool linearSearch(node* &head, int k){
	node* temp = head;
	while(temp){
		if(temp->data == k) return true;
		temp = temp->next;
	}
	return false;
}
void printList(node* &head){
	node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(){
	int n,data,k;
	cout<<"Enter the Size of linked list:- "<<endl;
	cin>>n;
	node* head=NULL,*temp=NULL;	
	for(int i=0; i<n; i++){
		cin>>data;
		node* newnode = new node(data);
		if(head==NULL){
			head = temp = newnode;
		}else{
			temp->next = newnode;
			temp = newnode;
		}
	}
	cout<<"List Element :- "<<endl;
	printList(head);
	cout<<"Enter the element to Search:- "<<endl;
	cin>>k;
	if(linearSearch(head,k)) cout<<"Element Found"<<endl;
	else cout<<"Element Not Found"<<endl;
	
}