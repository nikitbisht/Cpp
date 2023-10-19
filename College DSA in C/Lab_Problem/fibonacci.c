/*
Qn5:- Write a program in C to display the first n terms of fibonacci series using Recursion?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
int fibo(int n){
    //base case
    if(n==1||n==0){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    printf("Enter the number:- ");
    scanf("%d",&n);
    printf("Fibonacci Series of first %d terms is:- \n",n);
    for(int i=0;i<n;i++){
        printf("%d ",fibo(i));
    }
}
/*
1.Input:- 
Enter the number:- 5
Output:
Fibonacci Series of first 5 terms is:- 
0 1 1 2 3 

2.Input:-
Enter the number:- 8
Output:
Fibonacci Series of first 8 terms is:- 
0 1 1 2 3 5 8 13 

3.Input:- 
Enter the number:- 10
Output:
Fibonacci Series of first 10 terms is:- 
0 1 1 2 3 5 8 13 21 34 
*/