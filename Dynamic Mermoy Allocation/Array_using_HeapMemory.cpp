//Array using Heap Memory
#include<iostream>
using namespace std;
inline void print(int arr[],int &n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main(){
	int n;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	print(arr,n);
	delete []arr;
	return 0;
}