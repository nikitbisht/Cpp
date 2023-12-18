//Merge sort in ll
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
node* findMid(node* head){
	node* slow = head;
	node* fast = head->next;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
node* mergeList(node* left , node* right){
	node* dummyhead = (node*)malloc(sizeof(node));
	node* dummytail =  dummyhead;
	while(left && right){
		if(left->data<right->data){
			dummytail->next = left;
			dummytail = left;
			left = left->next;
		}else{
			dummytail->next = right;
			dummytail = right;
			right = right->next;
		}
	}
	if(left){
		dummytail->next = left;
	}
	if(right){
		dummytail->next = right;
	}
	node* temp = dummyhead;
	dummyhead = dummyhead->next;
	free(temp);
	return dummyhead;
}
node*  mergeSort(node* head){
	//base case
	if(!head || !head->next) 	return head;
	//find mid
	node* mid = findMid(head);
	// break into 2 halfes
	node* left = head;
	node* right = mid->next;
	mid->next=NULL;
	
	left = mergeSort(left);
	right = mergeSort(right);
	
	return mergeList(left , right);
}
int main(){
	node* head = NULL;
	head = createList(head);
	displayList(head);
	head = mergeSort(head);
	printf("\nhello\n");
	displayList(head);
	return 0;
}