#include<iostream>
#define maxSize 100
using namespace std;
void shellSort(int* arr,int n){
	for(int gap = n/2; gap>=1; gap/=2){
		for(int j=gap; j<n; j++){
			for(int i=j-gap; i>=0; i=i-gap){
				if(arr[i+gap] > arr[i]){
					break;
				}else{
					swap(arr[i],arr[i+gap]);
				}
			}
		}
	}
}
int main() {
    int n;
    cout<<"Size of array:- "<<endl;
    cin>>n;
    int arr[maxSize];
    cout<<"Enter Array Element:- "<<endl;
    for(int i=0; i<n; i++){
    	cin>>arr[i];
	}
	cout<<"Array Element After Shell Sort:- "<<endl;
	shellSort(arr,n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
