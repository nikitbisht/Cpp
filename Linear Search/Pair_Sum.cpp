/*
Qn:- Find Pair sum(work on Shorted array)
Ex:
arr[]={1,2,3,4,5}
sum=5
ans=1,4		2,3

*/
#include<iostream>
using namespace std;
int pair_sum(int arr[],int n,int s){
	int arr2[10];
	//two pointer approch
	int j=n-1,i=0,k=0;
	while(i<j){
		if(arr[i]+arr[j]==s){
			arr2[k]=arr[j];
			arr2[k+1]=arr[i];
			i++;
			k=k+2;
			j--;
		}
		else if(arr[i]+arr[j]<s)
			i++;
		else
			j--;
	} 
	for(i=0;i<k;i++)
		cout<<arr2[i]<<" ";
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
//	int arr[]={1,2,3,4,5,6,7,8};
	int k;
	cin>>k;
	pair_sum(arr,n,k);
	return 0;
}
