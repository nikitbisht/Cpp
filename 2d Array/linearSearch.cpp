//Linear Search in 2D array
#include<iostream>
using namespace std;
int isPresent(int arr[][10],int target,int n,int m){		
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j]==target){
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int arr[10][10];
	int n,m;
	cout<<"Enter the no of rows and coloum "<<endl;
	cin>>n>>m;
	cout<<"Enter Array Element:- "<<endl;
	for(int i=0; i<n; i++) {
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
	cout<<"Enter the target value:- "<<endl;
	int target;
	cin>>target;
	if(isPresent(arr,target,n,m))
		cout<<"Target Present"<<endl;
	else
		cout<<"Not Present"<<endl;
	return 0;
}
