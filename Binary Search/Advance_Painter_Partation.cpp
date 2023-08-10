//Painter Partation Problem
/*

*/
#include<iostream>
using namespace std;
bool is_possible(int arr[],int mid,int n,int k){
	int painter=1;
	int board=0;
	for(int i=0;i<n;i++){
		if(board+arr[i]<=mid){
			board+=arr[i];
		}
		else{
			painter++;
			if(painter>k||arr[i]>mid)
				return false;
		}
	}
	return true;
}
int Painter_partation(int arr[],int sum,int n,int k){
	int start=0;
	int end=sum;
	int ans=-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(is_possible(arr,mid,n,k)){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}
int main(){
	int n,sum=0;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	int ans=Painter_partation(arr,sum,n,k);
	cout<<ans<<endl;
	return 0;
}
