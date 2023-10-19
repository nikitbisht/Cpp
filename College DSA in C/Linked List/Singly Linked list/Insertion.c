#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    
};
struct node* newnode,*head=0,*temp;
//display linked list
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
//Insertion at the Begning
void insertionAtBegning(){
    printf("\nEnter the element you wanna insert at begning:= ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
//Insertion at end;
void insertionAtEnd(){
    printf("\nEnter the element you wanna insert at End:= ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    temp=newnode;
}
//Insertion at Specifix position
void insertionAtPostion(){
    int n,i=1;
    printf("Enter the postion: ");
    scanf("%d",&n);
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(n==1){
    	newnode->next=head;
    	head=newnode;
        return;
    }
    temp=head;
    while(i!=n-1){
        temp=temp->next;
        i++;
    }
	newnode->next=temp->next;
    temp->next=newnode;
}
int main(){
    int n;
    printf("Enter the no of element you wanna add:- ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    display();
    // insertionAtBegning();
    // display();
    // insertionAtEnd();
    // display();
    insertionAtPostion();
    display();
    return 0;
}