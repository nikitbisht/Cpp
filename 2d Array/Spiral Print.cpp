// Spiral Print (Amazon)
#include<iostream>
using namespace std;
int rowsum(int arr[][10],int n,int m) {
	int count=0;
	int total=m*n;
	int sr=0;				//starting row
	int sc=0;				//starting column
	int er=n-1;				//ending row
	int ec=n-1;				//ending column
	while(count<total) {
		for(int i= sc; i <=ec; i++) {
			cout<<arr[sr][i]<<" ";
			count++;
		}
		sr++;
		for(int i= sr; i <=er; i++) {
			cout<<arr[i][ec]<<" ";
			count++;
		}
		ec--;
		for(int i= ec; i >=sc; i--) {
			cout<<arr[er][i]<<" ";
			count++;
		}
		er--;
		for(int i= er; i>=sr; i--) {
			cout<<arr[i][sc]<<" ";
			count++;
		}
		sc++;
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
	rowsum(arr,n,m);
	return 0;
}