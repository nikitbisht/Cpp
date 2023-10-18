/*
Kadane's Algorithm
	Maximum contiguous Subarray Sum
*/
#include<iostream>
using namespace std;
#define Max_Size 10
int kadanesAlgo(int arr[],int &n){
	int sum=0;
	int maxi=arr[0];
	for(int i=0;i<n;i++){
		sum+=arr[i];
		maxi=max(maxi,sum);
		if(sum<0)
			sum=0;
	}
	return maxi;
}
int main(){
	int n;
	cout<<"Enter array Size:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl;
	cout<<"Kadane's Algorithm(Maximum Contiguous Subarray Sum)"<<endl<<kadanesAlgo(arr,n);
	return 0;
}