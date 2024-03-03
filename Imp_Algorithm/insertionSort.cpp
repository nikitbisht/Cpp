#include<iostream>
#define max 100
using namespace std;
//Insertion Sort
void insertionSort(int *arr, int n){
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j >=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;			
		}
		arr[j+1] = key;
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
	insertionSort(arr,n);
	cout<<"Array element after Insertion Sort:- "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}