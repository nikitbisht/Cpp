#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*pre;
}*head=0,*tail=0,*temp,*newnode=0;
//traverse
void display(){
	printf("%d||%d\n",head->data,tail->data);
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void insertAtHead(){
	newnode->pre=NULL;
	head->pre=newnode;
	newnode->next=head;
	head=newnode;
}
void insertAtEnd(){
	newnode->next=NULL;
	newnode->pre=tail;
	tail->next=newnode;
}
void insertion(){
	int n;
	scanf("%d",&n);
	printf("Enetr the elemetn;_ ");
	newnode=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	if(n==1){
		insertAtHead();
		return ;
	}
	int cnt=1;
	temp=head;
	while(cnt<n-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		insertAtEnd();
		return; 
	}
	temp->next->pre=newnode;
	newnode->pre=temp;
	newnode->next=temp->next;
	temp->next=newnode;
}
void deletion(){
	printf("posi:-");
	int n;
	scanf("%d",&n);
	if(n==1){
		head=head->next;
		head->pre=NULL;
	}
	else{
		int cnt=1;
		node*pre=NULL;
		node*cur=head;
		while(cnt<n){
			pre=cur;
			cur=cur->next;
			cnt++;
		}
		if(cur->next==NULL){
			tail=pre;
			tail->next=NULL;
		}
		cur->pre=NULL;
		pre->next=cur->next;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		node*newnode=(struct node*)malloc(sizeof(struct node));
			scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL){
			head=temp=newnode;
			tail=newnode;
			newnode->pre=NULL;
		}
		else{
			temp->next=newnode;
			temp=newnode;
			tail=newnode;
		}
	}
	display();
	up:
		int m;
	printf("1. insertion\n2.deletion\n");
	scanf("%d",&m);
	if(m==1){
		insertion();
	}
	else{
		deletion();
	}
	display();
	goto up;
	return 0;
}