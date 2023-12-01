#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	char Product_Id[20];
	char Product_Name[100];
	int Total_Sale;
	char Product_Grade;
	struct node* next;
} node;
void insertInNode(node*newnode){
	newnode->next=NULL;
	printf("Enter Product id:- ");
	getchar();
	scanf("%[^\n]s",&newnode->Product_Id);
	printf("Enter Product Name:- ");
	getchar();
	scanf("%[^\n]s",&newnode->Product_Name);
	printf("Enter Total Sale:- ");
	getchar();
	scanf("%d",&newnode->Total_Sale);
	printf("Enter Product Grade:- ");
	getchar();
	scanf("%c",&newnode->Product_Grade);
}
void enqueue(node** front,node** rear,int* size,int* count) {
	if(*count==*size) {
		printf("Queue Overflow");
	} else {
		node* newnode=(node*)malloc(sizeof(node));
		if(*front==NULL) {
			*count++;
			insertInNode(newnode);
			*front=newnode;
			*rear=newnode;
		}else{
			*count++;
			insertInNode(newnode);
			(*rear)->next=newnode;
			*rear=newnode;
		}
	}
}
void dequeue(node**front,int* size){
	if(front==NULL){
		printf("Queue UnderFlow");
	}else{
		(*size)--;
		node* temp=*front;
		*front=(*front)->next;
		free(temp);
	}
}
void displayQueue(node* front,int*size){
	if(*size==0){
		printf("\nQueue is Empty\n");
		return ;
	}
	node* temp=front;
	while(temp!=NULL){
		printf("\n\nDetails of the Product:- ");
		printf("\nProduct Id:- %s ",temp->Product_Id);
		printf("\nProduct Name:- %s ",temp->Product_Name);
		printf("\nTotal Sale:- %d ",temp->Total_Sale);
		printf("\nProduct Grade:- %c ",temp->Product_Grade);
		temp=temp->next;
	}
}
void AddQueue(node** front,node** rear,int* size,int* count){
	printf("Enter the no of Element Add in Queue:- ");
	scanf("%d",&(*size));
	for(int i=0; i<(*size); i++) {
		printf("\nEnter the Details of a Product:- \n");
		enqueue(front,rear,size,count);
	}
}
void DeletionInQueue(node** front,int* size){
	if(*size==0){
		printf("\nQueue is Empty\n");
		return ;
	}
	int n;
	printf("\nEnter the no of Element to Delete:- ");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		dequeue(front,size);
	}
}
int main() {
	node* front = NULL;
	node* rear = NULL;
	int size=0;
	int count=0;
	int n;
	up:
	printf("\nEnter the Operation:- ");
	printf("\n1. Add element in Queue(enqueue) ");
	printf("\n2. Delete element from Queue(dequeue) ");
	printf("\n3. Display Queue ");
	printf("\n4. Exit");
	printf("\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			AddQueue(&front,&rear,&size,&count);
			break;
		case 2:
			DeletionInQueue(&front,&size);
			break;
		case 3:
			displayQueue(front,&size);
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid Input");
	}
	goto up;
	return 0;
}