//Bubbel Sort Using Recursion
#include<iostream>
#define Max_Size 10
using namespace std;
//Print Array
void displayArray(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
}
void bubbleSort(int *arr,int n){
	//base case
	if(n==1||n==0){
		return ;
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	bubbleSort(arr,n-1);
}
int main(){
	int n;
	cout<<"Size of Array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Array Element:- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bubbleSort(arr,n);
	displayArray(arr,n);
	return 0;
}