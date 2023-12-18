//insertion in linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* createList(node* head){
	node* temp = NULL;
	int n;
	printf("No of elment in list:- ");
	scanf("%d",&n);
	printf("Enter the data:- ");
	for(int i = 0;i<n;i++){
		node* newnode = (node*)malloc(sizeof(node));
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		if(!head){
			head = temp = newnode;
		}else{
			temp->next = newnode;
			temp = newnode;
		}
	}
	return head;
}
void displayList(node* head){
	node* temp = head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
node* insertAtHead(node* head,int val){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next = head;
	return newnode;
}
node* insertMiddle(node* head,int posi , int val){
	if(posi==1){
		head = insertAtHead(head,val);
		return head;
	}
	int cnt = 1;
	node* temp = head;
	while(cnt<posi-1){
		temp=temp->next;
		cnt++;
	}
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = val;
	newnode->next = temp->next;
	temp ->next = newnode;
	return head;
}
int main(){
	node* head = NULL;
	head = createList(head);
	displayList(head);	
	int k ,n;
	printf("Enter the element:= ");
	scanf("%d",&k);
	printf("which posi");
	scanf("%d",&n);
	head = insertMiddle(head,n,k);
	displayList(head);
	return 0;
}