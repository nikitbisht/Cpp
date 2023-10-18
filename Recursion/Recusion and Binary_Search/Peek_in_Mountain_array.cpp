//Peak in a Mountain Array
/*
Qn:- Find the peak value in Mountain array
Ex:- n=6
{1,2,4,5,3,2}
O/p:- 5
*/
#include<iostream>
using namespace std;
#define Max_Size 10
int peek(int *arr,int s,int e){
	//base case
	if(s>=e)
		return s;
	int mid=s+(e-s)/2;
		
	if(arr[mid]<=arr[mid+1])
		return peek(arr,mid+1,e);
	else
		return peek(arr,s,mid);
}
int main(){
	int n;
	int arr[Max_Size];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int ans=peek(arr,0,n-1);
	cout<<ans<<endl;
	return 0;
}
