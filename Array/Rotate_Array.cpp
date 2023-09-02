//Rotate Array
//focus on case then code
#include<iostream>
using namespace std;
int rotate(int arr[],int arr1[],int n,int k){
	
	for(int i=0;i<n;i++){
		arr1[(i+k)%n]=arr[i];
	}
	return 0;
}
int main(){ 
	int n,k;
	cin>>n;
	int arr[100],arr1[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	rotate(arr,arr1,n,k);
	for(int i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	return 0;
}
