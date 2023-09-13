//Selection Sort
/*
Best case --> O(n^2)
Worst case --> O(n^2)
Use Case --> when array/vector/list has "Small size"
*/
#include<iostream>
using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int minindex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		swap(arr[i],arr[minindex]);
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	selection_sort(arr,n);
	cout<<"Sorted Array:"<<endl;
	printarray(arr,n);
	return 0;
}
