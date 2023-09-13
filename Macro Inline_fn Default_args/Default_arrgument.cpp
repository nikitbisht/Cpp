/*
Default Arrgument:- dena hai to de ni toh mai to assume kr he lunga
Condition:
	it allway start from RIGHT MOST PARAMETER
*/
#include<iostream>
#define Max_Size 100
using namespace std;
inline void print(int arr[],int &n,int start=0){
	for(int i=start;i<n;i++)
		cout<<arr[i]<<" ";
}

int main(){
	int n,m;
	cout<<"Enter the size of array:0- "<<endl;
	cin>>n;
	int arr[Max_Size];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter 99 to start array from 0:-"<<endl;
	cout<<"Enter another to start array from that no:- "<<endl;
	cin>>m;
	if(m==99)
		print(arr,n);
	else if(m>=0&&m<n)
		print(arr,n,m);
	else
		cout<<"errro"<<endl;
	return 0;
}