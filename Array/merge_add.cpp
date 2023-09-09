//merge shorted array
/*
i/p= [1,2,3]
i/p= [2,4,5]
o/p=[1,2,2,3,4,5]
*/
//focus on case then code
#include<iostream>
using namespace std;
void merge(int arr1[],int arr2[],int n,int m){
		int i=n-1;
		int j=m-1;
		int k=m+n-1;
		while(j>=0&&i>=0){
			if(arr1[i]<arr2[j]){
				arr1[k]=arr2[j];
				k--;
				j--;
			}
			else{
				arr1[k]=arr1[i];
				i--;
				k--;
			}
		}
		while(j>=0){
			arr1[k]=arr2[j];
			j--;
			k--;
		}
		for(i=0;i<n+m;i++)
		cout<<arr1[i]<<" ";
}
int main(){
	int n,m;
	cin>>n;
	int arr1[100],arr2[100];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	merge(arr1,arr2,n,m);
	return 0;
}
