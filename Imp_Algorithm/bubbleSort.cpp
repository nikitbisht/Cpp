#include<iostream>
#define max 100
using namespace std;

//Bubble Sort
void bubbleSort(int *arr, int n){
	for(int i=0; i<n-1; i++){
		bool flag = true;
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
				flag = false;
			}
		}
		if(flag) return ;
	}
	return ;
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
	bubbleSort(arr,n);
	cout<<"Array element after Bubble Sort:- "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}