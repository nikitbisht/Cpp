//Build Max heap, Start form 0th index
#include <bits/stdc++.h> 
void heapify(vector<int>&arr,int i,int n){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(i!=largest){
		swap(arr[i],arr[largest]);
		heapify(arr, largest, n);
	}
}
vector<int> buildHeap(vector<int> arr, int n){	
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,i,n);
	}
	return arr;
}
