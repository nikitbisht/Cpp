//REverse LInked list in k group
#include<stdio.h>
#include<stdlib.h>
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
struct node* kReverse(struct node*temp,int k){
	//base case
	if(temp==NULL){
		return NULL;
	}
	//step1: reverse in k grup
	struct node*next=NULL;
	struct node*cur=temp;
	struct node*pre=NULL;
	int count=0;
	while(cur!=NULL&&count<k){
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
		count++;
	}
	//step2: Aage recursion deklega
	if(next!=NULL){
		temp->next=kReverse(next,k);
	}
	//return head of reverse
	return pre;
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
	head=kReverse(head,2);
	display();
}