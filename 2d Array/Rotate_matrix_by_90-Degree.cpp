// Rotate Matrix
/*
1 2 3
4 5 6
7 8 9
*/
#include<iostream>
using namespace std;
void print(int arr[][10],int n) {
	cout<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int rotate_90Degree(int arr[][10],int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(arr[i][j],arr[j][i]);
		}
	}
		print(arr,n);
	//swap
	for(int i=0; i<=n; i++) {
		for(int j=0; j<n/2; j++) {
			swap(arr[i][j],arr[i][n-1-j]);
		}
	}
	return 0;
}
int main() {
	int arr[10][10];
	int n;
	cout<<"Enter the no of rows and coloum "<<endl;
	cin>>n;
	cout<<"Enter Array Element:- "<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>arr[i][j];
		}
	}
//	print(arr,n);
	rotate_90Degree(arr,n);
	print(arr,n);
	return 0;
}