//Check LInked list id Circular or not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
	int data;
	struct node*next;
}*head,*temp,*newnode;
void display() {
	temp=head;
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
struct node* isLoop(){		//floyd detect loop
	if(head==NULL){
		return NULL;
	}
	temp=head;
	struct node*slow=head;
	struct node*fast=head;
	while(slow!=NULL&&fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
		if(slow==fast)
			return slow;
	}
	return NULL;
}
struct node* startingOfLoop(){
	if(head==NULL){
		return NULL;
	}
	struct node* interaction= isLoop();
	struct node*slow=head;
	while(slow!=interaction){
		slow=slow->next;
		interaction=interaction->next;
	}
	return slow;
}
void removecycle(){
	if(head==NULL){
		return ;
	}
	struct node* startingEnd=startingOfLoop();
	struct node*temp=startingEnd->next;
	while(temp->next!=startingEnd){
		temp=temp->next;
	}
	temp->next=NULL;	
}
int main() {
	int n;
	printf("Enter the size of:- ");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL) {
			temp=head=newnode;
		} else {
			temp->next=newnode;
			temp=newnode;
		}
	}
	temp->next=head->next;
	if(isLoop()!=NULL){
		printf("LOOP PRESENT (by flyod detection algo)\n");
	}
	else{
		printf("NO LOOP");
	}
	struct node*slow=startingOfLoop();
	printf("%d \n",slow->data);
	//remove cycle
	removecycle();
	display();
}