/*
Qn:- Find the peak value in Mountain array
Ex:- n=6
{1,2,4,5,3,2}
O/p:- 5
*/
#include<iostream>
using namespace std;
int peak(int arr[],int n ){			
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	while(start<end){
		if(arr[mid]<arr[mid+1]){
			start=mid+1;
		}
		else
			end=mid;						//mid-1 --> {1,2,5,2,1}
		mid=start+(end-start)/2;
	}
	return start;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int ans=peak(arr,n);
	cout<<ans<<endl;
	return 0;
}
