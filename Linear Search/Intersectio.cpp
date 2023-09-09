/*
Qn:- Find Intersection element  
condition array is in sorted form
Ex:
n=7
arr[]={1,4,5}
arr1[]={3,4,5}
ans=4,5
*/
#include<iostream>
#include<vector>
using namespace std;
int intersection(int arr[],int arr1[],int n,int m){
	int arr2[5];
	//two pointer approch
	int j=0,i=0,k=0;
	while(i<n&j<m){
		if(arr[i]==arr1[j]){
			arr2[k]=arr1[j];
			i++;
			k++;
			j++;
		}
		else if(arr[i]<arr1[j])
			i++;
		else
			j++;
	} 
	for(i=0;i<k;i++)
		cout<<arr2[i]<<" ";
	return 0;
}
int main(){
	int n,m;
	int arr[100],arr1[100];
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<m;i++)
		cin>>arr1[i];		
	intersection(arr,arr1,n,m);
	return 0;
}
