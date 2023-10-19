/*
Qn12:- Given two polynomial numbers represented by linked list, develop a program in C using a functions that adds these lists.(Adding merans to add the coefficients who have the same variable powers.)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    int cofficient;
    struct node*next;
}*p=0,*q=0,*res=0,*temp,*newnode;
void createList(struct node* *x){
    int choice;
    printf("\nEnter the no of element :- ");
    scanf("%d",&choice);
    for (int i=0;i<choice;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data:- ");
        scanf("%d",&newnode->data);
        printf("Enter the cofficient:- ");
        scanf("%d",&newnode->cofficient);
        newnode->next=0;
        if(*x==0){
            temp=newnode;
            *x=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}
void display(struct node *x){
    temp=x;
    while (temp!=NULL){
        printf("\nData:- %d\t cofficient:- %d",temp->data,temp->cofficient);
        temp=temp->next;
    }
}
void add(){
    while (p!=NULL&&q!=NULL){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        if(res==0){
            res=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        if(p->cofficient>q->cofficient){
            temp->data=p->data;
            temp->cofficient=p->cofficient;
            p=p->next;
        }
        else if(q->cofficient>p->cofficient){
            temp->data=q->data;
            temp->cofficient=q->cofficient;
            q=q->next;
        }
        else{
            temp->data=q->data+p->data;
            temp->cofficient=q->cofficient;
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        temp->next=newnode;
        temp=newnode;
        temp->data=p->data;
        temp->cofficient=p->cofficient;
        p=p->next;
    }
    while(q!=NULL){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        temp->next=newnode;
        temp=newnode;
        temp->data=q->data;
        temp->cofficient=q->cofficient;
        q=q->next;
    } 
}
int main(){
    printf("\nEnter First polynomial data:- \n");
    createList(&p);
    printf("\nEnter second polynomial data:- \n");
    createList(&q);
    printf("\n\nfirst polynomial:- ");
    display(p);
    printf("\n\nsecond polynomial:-");
    display(q);
    add();
    printf("\n\nAddition of two polynomila is :- ");
    display(res);
    return 0;
}
/*
1.Input:-

Enter First polynomial data:- 
Enter the no of element :- 3

Enter the data:- 3
Enter the cofficient:- 2
Enter the data:- 2
Enter the cofficient:- 1
Enter the data:- 9
Enter the cofficient:- 0

Enter second polynomial data:- 
Enter the no of element :- 3

Enter the data:- 6
Enter the cofficient:- 3
Enter the data:- 5
Enter the cofficient:- 2
Enter the data:- 9
Enter the cofficient:- 1


First polynomial:- 
Data:- 3         cofficient:- 2
Data:- 2         cofficient:- 1
Data:- 9         cofficient:- 0

Second polynomial:-
Data:- 6         cofficient:- 3
Data:- 5         cofficient:- 2
Data:- 9         cofficient:- 1

Addition of two polynomila is :- 
Data:- 6         cofficient:- 3
Data:- 8         cofficient:- 2
Data:- 11        cofficient:- 1
Data:- 9         cofficient:- 0

2.Input:-

Enter First polynomial data:- 
Enter the no of element :- 3

Enter the data:- 3
Enter the cofficient:- 2
Enter the data:- 2
Enter the cofficient:- 1
Enter the data:- 7
Enter the cofficient:- 0

Enter second polynomial data:- 
Enter the no of element :- 3

Enter the data:- 5
Enter the cofficient:- 3
Enter the data:- 2
Enter the cofficient:- 2
Enter the data:- 1
Enter the cofficient:- 1

first polynomial:- 
Data:- 3         cofficient:- 2
Data:- 2         cofficient:- 1
Data:- 7         cofficient:- 0

second polynomial:-
Data:- 5         cofficient:- 3
Data:- 2         cofficient:- 2
Data:- 1         cofficient:- 1

Addition of two polynomila is :- 
Data:- 5         cofficient:- 3
Data:- 5         cofficient:- 2
Data:- 3         cofficient:- 1
Data:- 7         cofficient:- 0

3.Input:-
Enter First polynomial data:- 
Enter the no of element :- 2

Enter the data:- 2
Enter the cofficient:- 5
Enter the data:- 3
Enter the cofficient:- 0

Enter second polynomial data:- 
Enter the no of element :- 1

Enter the data:- 2
Enter the cofficient:- 1

first polynomial:- 
Data:- 2         cofficient:- 5
Data:- 3         cofficient:- 0

second polynomial:-
Data:- 2         cofficient:- 1

Addition of two polynomila is :- 
Data:- 2         cofficient:- 5
Data:- 2         cofficient:- 1
Data:- 3         cofficient:- 0
*/