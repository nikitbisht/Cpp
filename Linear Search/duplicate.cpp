/*
Qn:- Find Duplicate element  
condition every element form 1 to n-1 are present in the array at least once
Ex:
n=7
arr[]={1,2,3,4,5,6,4}
ans=4
*/
#include<iostream>
using namespace std;
int duplicate(int arr[],int n){
	int ans=0;
	for(int i=0;i<n;i++){
		ans=ans^arr[i];
	}
	for(int i=1;i<n;i++)
		ans=ans^i;
	return ans;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<duplicate(arr,n)<<endl;
	return 0;
}
