//Seletion Sort using recursion
#include<iostream>
#define Max_Size 10
using namespace std;
//Print Array
void displayArray(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
}
void seletionSort(int *arr,int len,int n){
	//base case
	if(n==1){
		return ;
	}
	int j=len-n;			// here j is just finding the starting index of unshortedarray
	int index=j;
	int maxi = arr[j];
	for(int i=j+1;i<len;i++){		//in every recursive call starting element is sort
		if(arr[i]<maxi){
			maxi=arr[i];
			index=i;
		}
	}
	swap(arr[j],arr[index]);
	seletionSort(arr,len,n-1);
}
int main(){
	int n;
	cout<<"Size of Array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Array Element:- "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	seletionSort(arr,n,n);
	displayArray(arr,n);
	return 0;
}