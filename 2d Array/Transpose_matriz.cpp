// Transpose
/*
1 2 3			1 4 7
4 5 6			2 5 8
7 8 9			3 6 9
*/
#include<iostream>
using namespace std;
int transpose(int arr[][10],int n,int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(arr[i][j],arr[j][i]);
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
	transpose(arr,n,m);
	cout<<"After transpose "<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}