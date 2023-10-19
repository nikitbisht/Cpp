/*
Qn2:- Write a program in C to find array representation of sparse Matrices using a user defined function. 
Sparse matrix meanse Storing the non-zero elements of a matrix in a triple form-(row,column,value) ?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#define Max_Size 10
int k=0;
//Sparse Matrix
void sparseMatrix(int arr[][Max_Size],int n,int m, int ans[][Max_Size]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                ans[0][k]=i;
                ans[1][k]=j;
                ans[2][k++]=arr[i][j];
            }
        }
    }
}
//Display Sparse Matrix
void displaySparseMatrix(int arr[][Max_Size]){
    for(int i=0;i<3;i++){
        for(int j=0;j<k;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
//Display normal Matrix
void displayMatrix(int arr[][Max_Size],int n,int m){
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
    int ans[Max_Size][Max_Size];
    printf("Enter the no of rows:- ");
    scanf("%d",&n);
    printf("Enter the no of column:- ");
    scanf("%d",&m);
    printf("Enter the Matrix Element:- \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Input Matrix:- \n");
    displayMatrix(arr,n,m);
    sparseMatrix(arr,n,m,ans);
    printf("Sparse Matrix:- \n");
    displaySparseMatrix(ans);
    return 0;
}
/*
1.Input:-
Enter the no of rows:- 4  
Enter the no of column:- 4
Enter the Matrix Element:- 
1 0 2 0 0 0 7 4 0 0 0 0 2 3 0 0
Output:
Input Matrix:-
1 0 2 0
0 0 7 4
0 0 0 0
2 3 0 0
Sparse Matrix:-
0 0 1 1 3 3
0 2 2 3 0 1
1 2 7 4 2 3

2.Input:-
Enter the no of rows:- 3
Enter the no of column:- 4
Enter the Matrix Element:- 
0 1 6 5 0 2 1 0 3 0 9 0
Input Matrix:-
0 1 6 5
0 2 1 0
3 0 9 0
Sparse Matrix:-
0 0 0 1 1 2 2
1 2 3 1 2 0 2
1 6 5 2 1 3 9

3.Input:-
Enter the no of rows:- 2
Enter the no of column:- 3
Enter the Matrix Element:-
1 3 0 4 0 0
Ouput:
Input Matrix:-
1 3 0
4 0 0
Sparse Matrix:-
0 0 1
0 1 0
1 3 4
*/