//Dishes
#include<iostream>
using namespace std;
void Bubble_sort(int [],int );
bool ispossible(int arr[],int mid,int n,int k){
	int time=0;
	int dishes=0;
	int i=0,count=0;
	int arr1[100];
	while(i<n){
		if(dishes<=mid){
			time=time+arr[i];
			dishes+=time;
			count++;
		}
		else{
			i++;
			count--;
			dishes=0,time=0;
		}
	}
	if(count>=k)
		return true;
	return false;
}
int dishes(int arr[],int n,int k){
	int start=0;
	int end=100;
	int ans=-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(ispossible(arr,mid,n,k)){
			ans=mid;
			end=mid-1;
		}
		else
			start=mid+1;
		mid=start+(end-start)/2;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	Bubble_sort(arr,n);
	cout<<dishes(arr,n,k)<<endl;
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
