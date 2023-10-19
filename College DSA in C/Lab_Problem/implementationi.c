/*
Qn10:- Write a program in C to implement Following operation in a Doubly Linked list
1. Creation
2. Insertion
3. Deletion

Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*pre;
    int data;
    struct node*next;
}*head=0,*temp=0,*newnode=0;
int count=0;

//Display Linked List
void display(){
    printf("\nLinked List Element are:- \n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//Creation of Linked List
void creation(){
    int n;
    head=0;
    count=0;
    printf("Enter the size of linked list:- ");
    scanf("%d",&n);
    for (int  i = 0; i < n; i++){
        count++;
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            newnode->pre=0;
            temp=newnode;
            head=newnode;
        }
        else{
            temp->next=newnode;
            newnode->pre=temp;
            temp=newnode;
        }
    }
}
//insertion at begnning:
void insertBegnning(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Element:- ");
    scanf("%d",&newnode->data);
    newnode->pre=0;
    head->pre=newnode;
    newnode->next=head;
    head=newnode;
}
//Insertion at end
void insertEnd(){
    temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Element:- ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp->next=newnode;
    newnode->pre=temp;
    temp=newnode;
}
//Insertion in Linked list
void insertion(){
    if(head==0){
        printf("Element not found");
        exit(0);
    }
    int pos,i=1;
    temp=head;
    printf("Enter the postion:- ");
    scanf("%d",&pos);
    if(pos>count+1||pos<=0){
        printf("\nInvalid position");
        exit(0);
    }
    if(pos==1){
        count++;
        insertBegnning();
        return ;
    }
    else if(pos==count+1){
        count++;
        insertEnd();
        return ;
    }
    else if(pos>1&&pos<count+1){
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
    }
    count++;
    newnode=(struct node*)malloc (sizeof(struct node));
    printf("\nEnter the Element:- ");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->pre=temp;
    temp->next->pre=newnode;
    temp=newnode;
}
//Deletion at beggning
void deletionAtBeggning(){
    temp=head;
    temp=temp->next;
    head=head->next;
    temp->pre=0;
}
//Deletion at End
void deletionAtEnd(){
    temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->pre->next=0;
}
//Deletion in Linked list
void deletion(){
    if(head==0){
        printf("\nElement not found:");
        exit(0);
    }
    temp=head;
    int pos,i=1;
    printf("\nEnter the postion:- ");
    scanf("%d",&pos);
    if(pos>count){
        printf("\nInvalid position");
        exit(0);
    }
    if(pos==1){
        count--;
        deletionAtBeggning();
        return ;
    }
    else if(pos==count){
        deletionAtEnd();
        count--;
        return ;
    }
    else if(pos>1&&pos<count){
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
    }
    count--;
    temp->next=temp->next->next;
    temp->next->pre=temp;
    temp=temp->next;
}
int main(){
    int n;
    up:
    printf("\n\nEnter the operation:- \n");
    printf("1. Creation:- \n");
    printf("2. Insertion:- \n");
    printf("3. Deletion:- \n");
    printf("4. Exit:- \n");
    scanf("%d",&n);
    switch (n){
    case 1:
        creation();
        break;
    case 2:
        insertion();
        break;
    case 3:
        deletion();
        break;
    case 4:
        exit(0);
    default:
        break;
    }
        display();
    goto up;
    return 0;
}
/*
1.Input:-

Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
1
Enter the size of linked list:- 5
1 2 3 4 5
Linked List Element are:- 
1 2 3 4 5 

Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
2
Enter the postion:- 1
Enter the Element:- 0
Linked List Element are:- 
0 1 2 3 4 5 

Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
3

Enter the postion:- 1
Linked List Element are:- 
1 2 3 4 5 

2.Input & Output
Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
1
Enter the size of linked list:- 8
8 9 6 5 1 2 3 7
Linked List Element are:- 
8 9 6 5 1 2 3 7 

Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
2
Enter the postion:- 8
Enter the Element:- 10
Linked List Element are:- 
8 9 6 5 1 2 3 10 7 

Enter the operation:-
1. Creation:- 
2. Insertion:- 
3. Deletion:- 
4. Exit:- 
3
Enter the postion:- 2
Linked List Element are:- 
8 6 5 1 2 3 10 7 

*/