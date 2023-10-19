#include<stdio.h>
#include<stdlib.h>
struct node{
    /* data */
    int data;
    struct node*next;    
}*head=0,*newnode,*temp;
//display Linked List
void display(){
    temp=head;
    printf("\nLinked List\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
//Deletion from starting
void deletionFromBegging(){
    temp=head;
    head=temp->next;
}
//Deletion from End
void deletionFromEnd(){
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=0;
}
//Deletion from Specific Postion
void deletionFromSpecific(){
    int n,i=1;
    printf("\nEnter the position:- ");
    scanf("%d",&n);
    temp=head;
    while(i!=n-1){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}
int main(){
    int n;
    printf("Enter the no of element you want to add:- ");
    scanf("%d",&n);
    printf("Enter the element ");
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
    // deletionFromBegging();
    // display();
    // deletionFromEnd();
    // display();
    deletionFromSpecific();
    display();
    return 0;
}