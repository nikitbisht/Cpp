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
void deleteDublicate(){
	if(head==NULL){
		return;
	}
	struct node*cur=head;
	while(cur->next!=NULL){
		struct node*temp=cur->next;
//		struct node*pre=;
		while(temp!=NULL){
			if(cur->data==temp->data){
				temp-
			}
		}
	}
	
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
	display();
	deleteDublicate();
	display();
}