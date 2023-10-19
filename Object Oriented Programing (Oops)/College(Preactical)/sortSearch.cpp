#include<iostream>
#define Max_Size 20
using namespace std;
// Display array element
void display(int *arr,int n){
	cout<<"Array Element are:-"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
// Sort array element
void sortArray(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
// Search in Array
void searchElement(int*arr,int n){
	int k;
	cout<<"Enter the element you want to search:- "<<endl;
	cin>>k;
	for(int i=0;i<n;i++){
		if(arr[i]==k){
			cout<<"Element Present"<<endl;
			return ;
		}
	}
	cout<<"Element Not Present:"<<endl;
}
int main(){
	int n,m;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Enter array Element:- "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the operation:-"<<endl;
	cout<<"1. Sort the array:- "<<endl;
	cout<<"2. Search Element in array:- "<<endl;
	cin>>m;
	switch (m){
		case 1:
			sortArray(arr,n);
			break;
		case 2:
			searchElement(arr,n);
			break;
		default:
			cout<<"Invalid input"<<endl;
	}
	display(arr,n);
	return 0;
}