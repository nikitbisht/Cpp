#include<iostream>
#define max 100
using namespace std;
//Selection Sort
void selectionSort(int *arr, int n){
	for(int i=0; i<n-1; i++){
		int index = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		swap(arr[i],arr[index]);
	}
}

int main(){
	int n;
	cout<<"Enter the size of arrY:- "<<endl;
	cin>>n;
	int arr[max];
	cout<<"Enter array Element"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	selectionSort(arr,n);
	cout<<"Array element after Selection Sort:- "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}