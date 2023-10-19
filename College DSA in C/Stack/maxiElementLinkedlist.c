//Print Maximam element from a Linked list
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
	int data;
	struct node*next;
}*head=0,*temp,*newnode;
// return the maximun element from the linked list
int maxiElement(){
	temp=head;
	int maxi=INT_MIN;
	while(temp!=NULL){
		if(temp->data>maxi){
			maxi=temp->data;
		}
		temp=temp->next;
	}
	return maxi;
}
void display(){
	printf("Linked List Elements:-");
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	int n;
	printf("Enter the size of Linked list:- ");
	scanf("%d",&n);
	//Insert element in linked list
	for(int i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->next=0;
		scanf("%d",&newnode->data);
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	display();
	printf("\nMaximum Element in Linked list:- %d",maxiElement());
	return 0;
}