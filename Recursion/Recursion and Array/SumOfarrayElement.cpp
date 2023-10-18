//SUM of Element of Array
#include<iostream>
using namespace std;
#define Max_Size 10
int sum(int *arr,int n){
	//base case
	if(n==0){
		return arr[0];
	}
	int sum1=arr[0]+sum(arr+1,n-1);
	return sum1;
}
//int sum(int *arr,int n,int sum1=0){
//	//base case
//	if(n==0){
//		return arr[0];
//	}
//	sum1=sum(arr,n-1,sum1)+arr[n];
//	return sum1;
//	
//}
int main(){
	int n;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Enter the array Element:- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<sum(arr,n)<<endl;
	return 0;
}