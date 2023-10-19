/* 
Qn3:- Write a program in c to store the transpose of a matrix of order M x N and display to the output on the screen ?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#define Max_Size 10
void transpose(int arr[][Max_Size],int n ,int m){
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
}
void display(int arr[][Max_Size],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n,m;
    int arr[Max_Size][Max_Size];
    printf("Enter the no of rows:- ");
    scanf("%d",&n);
    printf("Enter the no of column:- ");
    scanf("%d",&m);
    printf("Enter Matrix Element:- ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Given Matrix:- \n");
    display(arr,n,m);
    transpose(arr,n,m);
    printf("Transpose of a Matrix is:- \n");
    display(arr,n,m);
    return 0;
}
/*
1.Input:- 
Enter the no of rows:- 3
Enter the no of column:- 3
Enter Matrix Element:- 1 2 3 4 5 6 7 8 9
Output:- 
Given Matrix:- 
1 2 3 
4 5 6 
7 8 9 
Transpose of a Matrix is:-
1 4 7
2 5 8
3 6 9

2.InPut:- 
Enter the no of rows:- 4
Enter the no of column:- 4
Enter Matrix Element:- 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Output:-
Given Matrix:- 
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16
Transpose of a Matrix is:-
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

3.Input:-
Enter the no of rows:- 2
Enter the no of column:- 2
Enter Matrix Element:- 1 2 3 4
Given Matrix:-
1 2
3 4
Ouput:
Transpose of a Matrix is:-
1 3
2 4
*/