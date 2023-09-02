//Rotate array left side
#include<iostream>
using namespace std;
int rotateLeft(int arr1[],int arr2[],int n,int k) {
	for(int i=0; i<n; i++) {
		arr2[(n+i-k)%n]=arr1[i];
	}
	return 0;
}
void printArray(int arr2[],int n) {
	for(int i=0; i<n; i++)
		cout<<arr2[i]<<" ";
}
int main() {
	int n,k;
	cin>>n;
	int arr1[100],arr2[100];
	for(int i=0; i<n; i++) {
		cin>>arr1[i];
	}
	cin>>k;
	rotateLeft(arr1,arr2,n,k);
	printArray(arr2,n);
}