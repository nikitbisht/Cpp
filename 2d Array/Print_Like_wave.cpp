// Print like a wave
#include<iostream>
using namespace std;
int rowsum(int arr[][10],int n,int m) {
	int j=0;
	for( int i=0; i<m; i++) {
		if(i&1) {
			for(j=n-1; j>=0; j--) {
				cout<<arr[j][i]<<" ";
			}
		} 
		else {
			for(j=0; j<n; j++) {
				cout<<arr[j][i]<<" ";
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
	rowsum(arr,n,m);
	return 0;
}