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

int circular() {
	if(head==NULL) {
		return 1;
	}
	temp=head->next;
	while(temp!=NULL&&temp!=head) {
		temp=temp->next;
	}
	if(temp->next==head)
		return 1;
	return 0;
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
//	display();
	printf("%d ",circular());
//	display();
}