/*
Qn9:-Write a C program to search an element k in single linked list with n elements?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*temp,*newnode,*head=0;
void display(){
    printf("\nLinked List:- ");
    temp=head;
    while (temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
}
void searchElement(int element){
    temp=head;
    while (temp!=NULL){
        if(temp->data==element){
            printf("\nElement Present");
            return ;
        }
        temp=temp->next;
    }
    printf("\nElement is not Present");
}
int main(){
    int n;
    printf("Enter the size of Linked List:- ");
    scanf("%d",&n);
    printf("Enter Linked list Element:- ");
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        scanf("%d",&newnode->data);
        if(head==0){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    int element;
    printf("Enter the Element:- ");
    scanf("%d",&element);
    display();
    searchElement(element);
    return 0;
}
/*
1.Input:-
Enter the size of Linked List:- 5
Enter Linked list Element:- 7 8 6 2 3
Enter the Element:- 8
Output:
Linked List:-  7 8 6 2 3
Element Present

2.Input:-
Enter the size of Linked List:- 6
Enter Linked list Element:- 1 2 3 8 5 4
Enter the Element:- 9
Output:
Linked List:-  1 2 3 8 5 4
Element is not Present

3.Input:-
Enter the size of Linked List:- 10
Enter Linked list Element:- 7 8 9 5 6 3 2 1 4 5   
Enter the Element:- 6
Output:
Linked List:-  7 8 9 5 6 3 2 1 4 5
Element Present
*/