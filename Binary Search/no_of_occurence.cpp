/*
Qn:- Find the no of occurence in the aray of the key value
Ex:- n=6
{1,2,2,2,3,4}
key=2
O/p:- 3
*/
#include<iostream>
using namespace std;
int first(int arr[],int n,int key){			//left side
	int start=0;
	int end=n-1;
	int ans=0;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(arr[mid]==key){
			ans=mid;
			end=mid-1;
		}
		else if(arr[mid]<key)
			start=mid+1;
		else
			end=mid-1;
		mid=start+(end-start)/2;
	}
	return ans;
}

int last(int arr[],int n,int key){		//right side
	int start=0;
	int end=n-1;
	int ans=0;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(arr[mid]==key){
			ans=mid;
			start=mid+1;
		}
		else if(arr[mid]<key)
			start=mid+1;
		else
			end=mid-1;
		mid=start+(end-start)/2;
	}
	return ans;
}

int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	pair<int ,int >p;
	p.first=first(arr,n,key);
	p.second=last(arr,n,key);
	cout<<p.second-p.first+1<<endl;
	return 0;
}
