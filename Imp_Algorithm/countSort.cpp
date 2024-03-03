#include<iostream>
#define maxSize 100
using namespace std;
int findMaxi(int* arr,int n){
	int maxi = INT_MIN;
	for(int i=0; i<n; i++){
		maxi = max(arr[i],maxi);
	}
	return maxi;
}
void countSort(int* arr,int n){
	//find max element
	int maxi = findMaxi(arr,n);
	//create Frequency array
	int freq[maxi+1] = {0};
	for(int i=0; i<n; i++){
		freq[arr[i]]++;
	}
	//Calcuate cummulative frequency
	for(int i=1; i<=maxi; i++){
		freq[i] += freq[i-1];
	}
	
	int ans[n];
	for(int i = n-1; i>=0; i--){
		ans[--freq[arr[i]]] = arr[i];
	}
	//copy into original ans
	for(int i=0; i<n; i++){
		arr[i] = ans[i];
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
	cout<<"Array Element After Count Sort:- "<<endl;
	countSort(arr,n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
