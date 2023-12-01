#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef  struct node {
	int data;
	struct node* next;
} node;

void insertNode(node** head,node** temp) {
	if(*head==NULL) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next=NULL;
		scanf("%d",&newnode->data);
		*temp=*head=newnode;
	} else {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->next=NULL;
		scanf("%d",&newnode->data);
		(*temp)->next=newnode;
		*temp=newnode;
	}
}

node* createList(node* head) {
	int n;
	node* temp=NULL;
	printf("\nEnter the no of Element you want to add:- ");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		insertNode(&head,&temp);
	}
	return head;
}

void displayList(node* head){
	node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

node* AlternateMerge(node* A,node* B){
	node*dummyhead=(node*)malloc(sizeof(node));
	node* dummyTail=dummyhead;
	while(A!=NULL && B!=NULL){
		dummyTail->next=A;
		dummyTail=A;
		A=A->next;
		dummyTail->next=B;
		dummyTail=B;
		B=B->next;
	}
	if(A!=NULL){
		dummyTail->next=A;
	}
	if(B!=NULL){
		dummyTail->next=B;
	}
	node* temp=dummyhead;
	dummyhead=dummyhead->next;
	free(temp);
	return dummyhead;
}
int main() {
	node* A=NULL;
	node* B=NULL;
	node* S=NULL;
	bool flag=false;
	int n;
	up:
	printf("\nEnter the Operation to Preform:- ");
	printf("\n1. Create and Display Linked List A ");
	printf("\n2. Create and Display Linked List B ");
	printf("\n3. Merge and Display Linked List");
	printf("\n4. Exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			A =createList(A);
			flag=true;
			printf("\nLinked list A:- ");
			displayList(A);
			break;
		case 2:
			B = createList(B);
			flag=true;
			printf("\nLinked list B:- ");
			displayList(B);
			break;
		case 3:
			if(!flag){ printf("Empty Linked list\n");	goto up;}
			S=AlternateMerge(A,B);
			printf("\nMerge Linked list:- ");
			displayList(S);
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid input\n");
	}
	goto up;
	return 0;
}