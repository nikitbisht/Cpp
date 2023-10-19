#include<stdio.h>
#define max_size 100
void push(int arr[],int* top){
    if(*top==max_size){
        printf("\nStack Overflow");
        return ;
    }
    else{
        *top=*top+1;
        scanf("%d",&arr[*top]);
    }
}

int pop(int arr[],int *top){
    if(*top==-1){
        printf("\nStack Underflow");
        return 0;
    }
    else{
        *top=*top-1;
        return arr[*top];
    }
}
int peek(int arr[],int *top){
    return arr[*top];
}
 void display(int arr[],int *top){
    for(int i=*top;i>=0;i--)
        printf("%d ",arr[i]);
}
int main(){
    int n,top=-1,m;
    printf("Enter the size of Stack:- ");
    scanf("%d",&n);
    int arr[max_size];
    for(int i=0;i<n;i++)
        push(arr,&top);
    printf("\nPeek Element in Stack:- %d",peek(arr,&top));
    printf("\nEnter the Element you wanna delete:- ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        pop(arr,&top);
    display(arr,&top);
    return 0;
}