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
	temp=head;
	while(temp!=NULL){
		if(temp->next!=NULL&&temp->data==temp->next->data){
			temp->next=temp->next->next;
		}
		else{
			temp=temp->next;
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