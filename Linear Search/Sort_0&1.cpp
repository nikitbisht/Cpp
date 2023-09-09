/*
Qn:- Sort 0&1
Ex:
arr[]={0,1,1,0,0,1}
arr[]={0,0,0,1,1,1}
*/
#include<iostream>
using namespace std;
int sort(int arr[],int n){
	int i=0,j=n-1;
	//two pointer approch
	while(i<j){
		if(arr[i]==0)
			i++;
		else if(arr[j]==1)
			j--;
		else{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
