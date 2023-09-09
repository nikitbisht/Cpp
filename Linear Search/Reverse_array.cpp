/*
Qn:- Reverse array
Ex:
arr[]={4,12,8,10}
arr[]={10,8,12,4}
*/
#include<iostream>
#include<math.h>
using namespace std;
int print(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

int reverse(int arr[],int n){
	int j=n-1,i=0;
//	for(i=0;i<(n/2);i++){
	while(i<j){
	swap(arr[i],arr[j]);
	i++;
	j--;
	}
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	reverse(arr,n);
	print(arr,n);
	return 0;
}
