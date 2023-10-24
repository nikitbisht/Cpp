// Cone a Linked List using next pointer and random pointer
/*
#1 Approch
	buorte force approch
		T.C:- O(n^2)
		S.C:- O(1)

#2 Approch:- Mapping
	Use of Map data Sturcture
		T.C:- O(n)
		S.C:- O(n)

#3 Approch:- Node Exchange (Optimize approch)
	node change method
		T.C:- O(n)
		S.C:- O(1)
*/
#include<iostream>
#include<map>
using namespace std;
class node {
		int data;
		node* next;
		node* random;
		node(int data) {
			this->data=data;
			this->next=NULL;
			this->random=NULL;
		}
};
//Insert at clone LL
void insertAtTail(node* &head,node*&tail,int val) {
	node*newnode=new node(val);
	if(head==NULL) {
		head=tail=newnode;
	} else {
		tail=tail->next=newnode;
	}
}
//#2 Approch:- use of Mapping
node* mapping(node* &head) {
	node* clonehead=NULL;
	node* cloneTail=NULL;
	node*temp=head;
	//Step1:- Clone a LL
	while(temp!=NULL) {
		insertAtTail(clonehead,cloneTail,temp->data);
		temp=temp->next;
	}
	//Step2:- setMap
	unordered_map<node*,node*>mapping;
	node* originalnode=head;
	node* clonenode=clonehead;
	while(originalnode!=NULL) {
		mapping[originalnode]=clonenode;
		originalnode=originalnode->next;
		clonenode=clonenode->next;
	}
	//Step3:- set random pointer
	originalnode=head;
	clonenode=clonehead;
	while(originalnode!=NULL) {
		clonenode->random=mapping[originalnode->random];
		originalnode=originalnode->next;
		clonenode=clonenode->next;
	}
	return clonehead;
}
// #3 Approch:- Change of node
node* mapping(node* &head) {
	node* clonehead=NULL;
	node* cloneTail=NULL;
	node*temp=head;
	//Step1:- Clone a LL
	while(temp!=NULL) {
		insertAtTail(clonehead,cloneTail,temp->data);
		temp=temp->next;
	}
	//Step2:- Change of node(merge nodes)
	node* originalnode=head;
	node* clonenode=clonehead;
	node* temp=NULL;
	while(orginalnode!=NULL&&clonenode!=NULL) {
		temp=originalnode->next;
		originalnode->next=clonenode;
		originalnode=next;

		temp=clonenode->next;
		clonenode->next=originalnode;
		clonenode=next;
	}
	//Step3:- Set random pointer
	originalnode=head;
	clonenode=clonehead;
	while(originalnode!=NULL) {
		if(originalnode->next!=NULL) {
			if(originalnode->random!=NULL) {
				originalnode->next->random=originalnode->random->next;
			} else {	//this is last case
				originalnode->next=original->random;	//NULL
			}
		}
		original=original->next;
	}
	//Step4:- revert changes done in step2
	originalnode=head;
	clonenode=clonehead;
	while(originalnode!=NULL&&clonenodehead!=NULL) {
		originalnode=clonenode->next;
		originalnode=originalnode->next;
		if(originalnode->next!=NULL) {
			clonenode=originalnode->next;
		}
		clonenode=clondenode->next;
	}
	return clonehead;
}
