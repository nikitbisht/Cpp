/*
Qn1:- Write a program in c to display the second largest element in an array using a user define fuction?
Name:- Nikit Singh Bisht
Roll no:- 39
Section:- D2
Branch:- B-tech(CSE)
*/
#include<stdio.h>
#include<limits.h>
#define Max_Size 40
int secondLargest(int *arr,int n){
    if(n<2)
        return -1;
    int firstMaxi=INT_MIN;
    int secondMaxi=INT_MIN;
    //finding 1st largest element
    for(int i=0;i<n;i++){
        if(arr[i]>firstMaxi){
            firstMaxi=arr[i];
        }
    }
    //finding 2nd largest element
    for(int i=0;i<n;i++){
        if(arr[i]>secondMaxi && arr[i]!=firstMaxi){
            secondMaxi=arr[i];
        }
    }
    return secondMaxi;
}
int main(){
    int n;
    printf("Enter the size of array:- ");
    scanf("%d",&n);
    int arr[Max_Size];
    printf("Enter array Element:- ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nSecond Largest Element in array is:- %d",secondLargest(arr,n));
    return 0;
}
/*
1 Input:-
Enter the size of array:- 5
Enter array Element:- 1 2 6 9 4
Output:
Second Largest Element in array is:- 6

2 Input:-
Enter the size of array:- 8
Enter array Element:- 7 9 4 58 7 1 6 0
Output:
Second Largest Element in array is:- 9

3 Input:-
Enter the size of array:- 5
Enter array Element:- -9 -8 -7 -10 5
Output:
Second Largest Element in array is:- -7
*/