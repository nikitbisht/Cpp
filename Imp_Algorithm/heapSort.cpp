//HeapSort
#include<iostream>
#define Max_Size 10
using namespace std;

void heapify(int i,int *arr,int n){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	if(left < n && arr[largest] < arr[left]){
		largest = left;
	}
	if(right < n && arr[largest] < arr[right]){
		largest = right;
	}
	if(largest != i){
		swap(arr[i],arr[largest]);
		heapify(largest,arr,n);
	}
}

void heapSort(int*arr,int n){
	int t= n;
	while(t){
		swap(arr[0],arr[t-1]);
		t--;
		heapify(0,arr,t);
	}
}
int main(){
	int n;
	cout<<"Array Size:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Array Element :- "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//Convert Array into MaxHeap
	for(int i = n/2-1; i>=0; i--){
		heapify(i,arr,n);
	}
	heapSort(arr,n);
	cout<<"Array Element after Heap Sort:- "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}