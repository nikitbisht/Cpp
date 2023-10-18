//Linear Search
#include<iostream>
using namespace std;
#define Max_Size 10
bool isPresent(int *arr,int n,int k){
	//base case
	if(n==0){
		return false;
	}
	if(arr[0]==k)
		return true;
	else{
		return isPresent(arr+1,n-1,k);
	}
}
int main(){
	int n,k;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Enter the array Element:- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the Element you wanna Search:- "<<endl;
	cin>>k;
	if(isPresent(arr,n,k))
		cout<<"Element is Present"<<endl;
	else 
		cout<<"Element is Not Present"<<endl;
	return 0;

	
}