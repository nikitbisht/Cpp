/*
Qn:- Swap Alternate
Ex:
arr[]={1,2,3,4,5,6}
arr[]={2,1,4,3,6,5}
*/
#include<iostream>
using namespace std;
int print(int arr[] ,int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
int swapalternate(int arr[],int n){
	int i=0;
	for(i=0;i<n;i+=2){
		if(i+1<n)
			swap(arr[i+1],arr[i]);
	}
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	swapalternate(arr,n);
	print(arr,n);
	return 0;
}
