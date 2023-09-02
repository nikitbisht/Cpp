/*
Qn:- Find Max and Min Element in the array
Ex:
arr[]={4,12,8,10}
Min=4	Max=12
*/
#include<iostream>
#include<math.h>
using namespace std;
int getmax(int arr[],int n){
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i]>max)		//max=max(max,arr[i])
			max=arr[i];
	}
	return max;
}
int getmin(int arr[],int n){
	int min=INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}

int main(){
	int n;
	int arr[100];
	cout<<"size of array:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Max:- "<<getmax(arr,n)<<endl;
	cout<<"Min:- "<<getmin(arr,n)<<endl;

	return 0;
}
