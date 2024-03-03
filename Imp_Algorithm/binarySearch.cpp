//Linear Search
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define max 100000
using namespace std;
bool binarySearch(int* arr,int start ,int end,int k){
	int mid = start + (end-start)/2;
	while(start <= end){
		if(arr[mid]==k){
			return true;
		}else if(arr[mid] > k){
			end = mid-1;
		}else{
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}
	return false;
}
int main(){
	int n,k;
	cout<<"Enter the size of array: "<<endl;
	cin>>n;
	
	int arr[max];
	for(int i=0; i<n; i++){
//		arr[i] = i+1;
		cin>>arr[i];
	}
	cout<<"\nEnter the element to Search:- "<<endl;
	cin>>k;
	clock_t t1,t2;
	t1 = clock();
	bool flag = binarySearch(arr,0,n-1,k);
	t2 = clock();
	
	if(flag) cout<<"Element present"<<endl;
	else cout<<"Element not present"<<endl;
	
	double time_taken = (double)t2-t1/(double)CLOCKS_PER_SEC;
	cout<<"Total time taken:- "<<time_taken<<endl;
	return 0;
}