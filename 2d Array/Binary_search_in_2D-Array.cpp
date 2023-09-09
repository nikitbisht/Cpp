// Binary Search in 2D array
#include<iostream>
using namespace std;
bool binarySearch(int arr[][10],int target,int n,int m) {
	int start=0;
	int end=n*m-1;
	int mid= start+(end-start)/2;
	while(start<end){
		int element=arr[mid/m][mid%m];
		if(element==target){
			return 1;
		}
		else if(element<target){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		mid= start+(end-start)/2;
	}
	return 0;
}

int main() {
	int arr[10][10];
	int n,m;
	cout<<"Enter the no of rows and coloum "<<endl;
	cin>>n>>m;
	cout<<"Enter Array Element:- "<<endl;
	for(int i=0; i<n; i++) {		//row
		for(int j=0; j<m; j++) {
			cin>>arr[i][j];
		}
	}
	cout<<"Your array is ready:- "<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int target;
	cout<<"Enter the target:- "<<endl;
	cin>>target;
	if(binarySearch(arr,target,n,m))
		cout<<"Present"<<endl;
	else 
		cout<<"Not Present"<<endl;
	return 0;
}