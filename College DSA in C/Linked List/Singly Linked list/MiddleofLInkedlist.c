//Middle in linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;	
}*head,*temp,*newnode;
void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
/*
int middle(){
	temp=head;
	int cnt=0;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	cnt=cnt/2;
	temp=head;
	int flag=0;
	while(flag<cnt){
		temp=temp->next;
		flag++;
	}
	return temp->data;
}
*/
struct node* getmiddle(){
	if(head==NULL||head->next==NULL){
		return head;
	}
	if(head->next->next==NULL){
		return head->next;
	}
	struct node*fast=head->next;
	struct node*slow=head;
	
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
	}
	return slow;
}
int main(){
	int n;
	printf("Enter the size of:- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL){
			temp=head=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	display();
	struct node* p=getmiddle();
	printf("%d \n",p->data);
//	printf("%d \n",middle1());
		display();
}