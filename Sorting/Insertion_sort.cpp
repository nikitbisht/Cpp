//Insertion Sort
#include<iostream>
using namespace std;
int insertion_sort(int arr[],int n){
	int i=0,j=0;
	for(i=1;i<n-1;i++){
		int temp=arr[i];
		for(j=i-1;j>=0;j--){
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}
			else
				break;
		}
		arr[j+1]=temp;	
	}
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	insertion_sort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
