//Binary Search
/*
Why Binary Search
Ager hamare ek solution nikale se ek particular part neglet hoo jaye orr hame pata chal jaye ki hamara 
soln dusre part mai hai tbh hum khe skte hai ki ya too binary search lagega

*/
#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			start=mid+1;
		else
			end=mid-1;
		mid=start+(end-start)/2;
	}
	return -1;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	int index=binarysearch(arr,n,key);
	if(index!=-1){
		cout<<index<<" Present"<<endl;
		return 0;
	}
	else
		cout<<"Not present"<<endl;
	return 0;
}
