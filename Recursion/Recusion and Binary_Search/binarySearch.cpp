// Binary Search Using Recursion
#include<iostream>
using namespace std;
#define Max_Size 10
int binarySearch(int*arr,int s,int e,int k){
	//base case
	//Element Apsent
	if(s>e)
		return -1;
	//Element Present
	int mid=s+(e-s)/2;
	if(k==arr[mid]){
		return mid;
	}
	//Recursion Call
	if(k>arr[mid])
		return binarySearch(arr,mid+1,e,k);
	else
		return binarySearch(arr,s,mid-1,k);
		
}
int main(){
	int n,k;
	cout<<"Enter the Sizef of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the Search Element:- "<<endl;
	cin>>k;
	int ans=binarySearch(arr,0,n-1,k);
	if(ans>=0)
		cout<<"Element Present at "<<ans<<" Position"<<endl;
	else
		cout<<"Element Not Present: "<<ans<<endl;
	return 0;
}
