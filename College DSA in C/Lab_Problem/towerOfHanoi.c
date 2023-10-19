/*
Q4:- Write a program in C to implement tower of Hanoi Problem
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>   
void towerOfHanoi(char S,char D,char A,int n){
    //base case
    if(n==1){
        printf("\n%c -> %c",S,D);
        return ;
    }
    towerOfHanoi(S,A,D,n-1);
    printf("\n%c -> %c",S,D);
    towerOfHanoi(A,D,S,n-1);
}
int main(){
    int n;
    printf("Enter the no of disk:- ");
    scanf("%d",&n);
    printf("\nSteps to Solve tower of Hanoi:- ");
    towerOfHanoi('A','C','B',n);
    return 0;
}
/*
1.Input:-
Enter the no of disk:- 3
Output:
Steps to Solve tower of Hanoi:- 
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C

2.Input:- 
Enter the no of disk:- 2
Output:
Steps to Solve tower of Hanoi:-
A -> B
A -> C
B -> C

3.Input:-
Enter the no of disk:- 4
Output:
Steps to Solve tower of Hanoi:-
A -> B
A -> C
B -> C
A -> B
C -> A
C -> B
A -> B
A -> C
B -> C
B -> A
C -> A
B -> C
A -> B
A -> C
B -> C
*/