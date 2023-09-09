// Row wise column wise  sum
#include<iostream>
using namespace std;
//Row wise input
int rowsum(int arr[][10],int n,int m) {
	for(int i=0; i<n; i++) {
		int ans=0;
		for(int j=0; j<m; j++) {
			ans+=arr[i][j];
		}
		cout<<"Sum of "<<i<<"th row is= "<<ans<<endl;
	}
	return 0;
}
//column wise input
int columnSum(int arr[][10],int n,int m) {
	for(int i=0; i<m; i++) {
		int ans=0;
		for(int j=0; j<n; j++) {
			ans+=arr[j][i];
		}
		cout<<"Sum of "<<i<<"th colom is= "<<ans<<endl;
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
	cout<<endl;
	columnSum(arr,n,m);
	return 0;
}