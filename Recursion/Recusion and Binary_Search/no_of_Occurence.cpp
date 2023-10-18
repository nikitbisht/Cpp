/*
Qn:- Find the no of occurence in the aray of the key value(Using Recursion)
Ex:- n=6
{1,2,2,2,3,4}
key=2
O/p:- 3
*/
#include<iostream>
using namespace std;
#define Max_Size 10
int first(int *arr,int s,int e,int k){
	int mid=s+(e-s)/2;
	//base case
	if(s>=e){
		return mid;
	}
	int ans,ans1;
	if(arr[mid]==k){
		ans= first(arr,mid+1,e,k);
		cout<<ans<<endl;
		ans1=first(arr,s,mid,k);
		cout<<ans1<<endl;
	}
	if(arr[mid]>k)
		return first(arr,s,mid-1,k);
	else
		return first(arr,mid+1,e,k);
	return ans-ans1-1;
}
int main(){
	int n;
	int arr[Max_Size];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	cout<<first(arr,0,n-1,key);
	return 0;
}
