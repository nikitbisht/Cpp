//Quick Sort
#include<iostream>
#define Max_Size 10
using namespace std;
void displayArray(int *arr,int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//partition of array
int partition(int *arr,int start,int end){
//Place Element in right place
	int pivot=arr[start];
	int count=0;
	for(int i=start+1;i<=end;i++){
		if(arr[i]<=pivot){
			count++;
		}
	}
	int pivotIndex=start+count;
	swap(arr[start],arr[pivotIndex]);
//condition |<a|a|>a|
	int first=start;
	int last=end;
	while(first < pivotIndex && last > pivotIndex){
		while(arr[first]<pivot){
			first++;
		}
		while(arr[last]>pivot){
			last--;
		}
		if(first<pivotIndex && last>pivotIndex){
			swap(arr[first++],arr[last--]);
		}
	}
	return pivotIndex;
}
void quickSort(int*arr,int start,int end){
//base case
	if(start>=end)
		return ;
	int part=partition(arr,start,end);
	
//left part
	quickSort(arr,start,part-1);
//Right part
	quickSort(arr,part+1,end);
}
int main(){
	int n;
	cout<<"Array Size:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Array Element :- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quickSort(arr,0,n-1);
	cout<<"Array element after Quick Sort:- "<<endl;
	displayArray(arr,n);
	return 0;
}