//Recursion And Binary Search
//Check the Given array is shorted or not
#include<iostream>
using namespace std;
#define Max_Size 10
bool isShorted(int *arr,int n){
	//base case
	if(n==1||n==0){
		return true;
	}
	if(arr[0]>arr[1])
		return false;
	else{
		return isShorted(arr+1,n-1);
	}
}
int main(){
	int n;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Enter the array Element:- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(isShorted(arr,n))
		cout<<"Array is Shorted"<<endl;
	else 
		cout<<"Array is Not Shorted"<<endl;
	return 0;
}