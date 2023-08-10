/*
Qn:- Find the Pivot element in array(sorted and rotated)
Ex:- n=5
{1,2,3,8,9}
pivot:- {8,9,1,2,3}
O/p:- 9 or 1
*/
#include<iostream>
using namespace std;
int pivot(int arr[],int n ){			
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	while(start<end){
		if(arr[0]<=arr[mid]){
			start=mid+1;
		}
		else
			end=mid;						//mid-1 --> {7,9,1,3,6}
		mid=start+(end-start)/2;
	}
//	cout<<start<<" "<<mid<<" "<<end<<" "<<endl;
	return start;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int ans=pivot(arr,n);
	cout<<ans<<endl;
	return 0;
}

