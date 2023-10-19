//Reversed LInked list
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
void reverseLinked(node*cur,node*pre){
	//base case
	if(cur==NULL){
		head=pre;
		return ;
	}
	node*forward=cur->next;
	reverseLinked(forward,cur);
	cur->next=pre;
	return;
}
*/
node* reverseLinked(struct node*head){
	//base case
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* chotihead=reverseLinked(head->next);
	head->next->next=NULL;
	head->next=chotihead;
	return chotihead;
}
/*
void reverseLinked(){
	struct node*pre=NULL;
	struct node*cur=head;
	while(cur!=NULL){
		node*forward=cur->next;
		cur->next=pre;
		pre=cur;
		cur=forward;
	}
	head=pre;
}
*/
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
	head=reverseLinked(head);
	display();
}