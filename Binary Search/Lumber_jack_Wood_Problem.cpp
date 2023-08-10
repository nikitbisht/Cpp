//Lumber jack Problem
#include<iostream>
using namespace std;
bool ispossible(int arr[],long long int mid,long long int n,long long int wood){
long long int cutwood=0;
   	for(int i=0;i<n;i++){
   		if(arr[i]>=mid){
   			cutwood+=arr[i]-mid;	
		}
	}
	if(cutwood>=wood){
	   	return true;
	}
	return false;
}
int maxi(int arr[],int n){
    int maxi=0;
    for(int i=0;i<n;i++){
    	maxi=max(arr[i],maxi);
	}
	return maxi;
}
int lumber_jack(long long int arr[],long long int n	long long int wood){
   	long long int start=0;
    long long int end=maxi(arr,n);
   	long long int mid=start+(end-start)/2;
   	long long int ans=-1;
	while(start<=end){
   		if(ispossible(arr,mid,n,wood)){
			ans=mid;
   			start=mid+1;			
		}
		else
			end=mid-1;
		mid=start+(end-start)/2;
	}
	return ans;
}
int main(){
   	long long int n,wood;
   	int arr[100];
   	cin>>n;
   	for(int i=0;i<n;i++)
   		cin>>arr[i];
	cin>>wood;
	cout<<lumber_jack(arr,n,wood)<<endl;
	return 0;
}
