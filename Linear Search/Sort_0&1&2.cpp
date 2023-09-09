/*
Qn:- Sort 0&1&2
Ex:
arr[]={0,1,2,0,1,1}
arr[]={0,0,1,1,1,2}
*/
#include<iostream>
using namespace std;
int sort(int arr[],int n){
	int i=0,j=n-1,k=0;
	//two pointer approch
	while(i<=j){
		if(arr[i]==0){
			swap(arr[i],arr[k]);
			i++;
			k++;
		}
		else if(arr[i]==2){
			swap(arr[i],arr[j]);
			j--;
		}
		else{
			i++;
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