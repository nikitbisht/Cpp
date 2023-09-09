// Row wise column wise  sum
#include<iostream>
using namespace std;
//Row wise input
int rowsum(int arr[][10],int n,int m) {
	int maxi =INT_MIN;
	int largestIndex=-1;
	for(int i=0; i<n; i++) {
		int ans=0;
		for(int j=0; j<m; j++) {
			ans+=arr[i][j];
		}
		if(maxi<ans) {
			maxi=ans;
			largestIndex=i;
		}
	}
	cout<<"Sum of element in largest column is "<<maxi<<" at index "<<largestIndex<<endl;
	return 0;
}

int columnSum(int arr[][10],int n,int m) {
	int maxi=INT_MIN;
	int largestIndex=-1;
	for(int i=0; i<m; i++) {
		int ans=0;
		for(int j=0; j<n; j++) {
			ans+=arr[j][i];
		}
		if(maxi<ans) {
			maxi=ans;
			largestIndex=i;
		}
	}
	cout<<"Sum of element in largest row is "<<maxi<<" at index "<<largestIndex<<endl;
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