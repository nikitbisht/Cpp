//Bubble Sort
#include<iostream>
using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void  Bubble_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		bool flag=true;
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				flag=false;
				swap(arr[j],arr[j+1]);
			}
		}
		if(flag==true)
			break;
	}
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	Bubble_sort(arr,n);
	printarray(arr,n);
	return 0;
}
