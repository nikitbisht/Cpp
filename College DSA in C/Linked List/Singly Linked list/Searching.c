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
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}
//Searching in linked list
void search(){
    int element ;
    printf("Enter the element you wanna search:- ");
    scanf("%d",&element);
    temp=head;
    while(temp!=0){
        if(temp->data==element){
            printf("Element present");
            return ;
        }
        temp=temp->next;
    }
    printf("Element Not Present");
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
    search();

    return 0;
}