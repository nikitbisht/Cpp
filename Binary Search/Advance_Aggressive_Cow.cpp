//Aggressive Cow Problem
/*
	Such that the minimun distance between any two cow is as large as possible
*/
#include<iostream>
using namespace std;
bool is_possible(int stall[],int mid,int n,int k){
	int cowcount=1;
	int lastpos=stall[0];			//first cow at 0 position
	for(int i=1;i<n;i++){
		if(stall[i]-lastpos>=mid){		//place for second cow at stall[i]
			cowcount++;
			if(cowcount==k)				//if place all cow return true
				return true;
			lastpos=stall[i];			
		}
	}
	return false;
}
int sort(int stall[],int n){
	for(int i=0;i<n-1;i++){
		bool flag=true;
		for(int j=0;j<n-i-1;j++){
			if(stall[j]>stall[j+1]){
				swap(stall[j],stall[j+1]);
				flag=false;
			}
		}
		if(flag==true)
			break;
	}
	return 0;
}
int Aggressive_cow(int stall[],int maxi,int n,int k){
	sort(stall,n);
	int start=0;
	int end=maxi;
	int ans=-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(is_possible(stall,mid,n,k)){
			ans=mid;
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int stall[100];
	for(int i=0;i<n;i++)
		cin>>stall[i];
	int k;
	cin>>k;
	int maxi=-1;
	for(int i=0;i<n;i++)
		maxi=max(stall[i],maxi);
	int ans=Aggressive_cow(stall,maxi,n,k);
	cout<<ans<<endl;
	return 0;
}
/*
Why Binary Search
Ager hamare ek solution nikale se ek particular part neglet hoo jaye orr hame pata chal jaye ki hamara 
soln dusre part mai hai tbh hum khe skte hai ki ya too binary search lagegaWhy Binary Search
*/
