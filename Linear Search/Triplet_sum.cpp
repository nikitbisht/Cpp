/*
Qn:- Find three Pair sum
Ex:
arr[]={1,2,3,4,5,6,7}
sum=5
ans=

*/
// did not work properly
#include<iostream>
using namespace std;
int bruteforce(int arr[] ,int n,int sum);

int pair_sum(int arr[],int n,int s){
	int arr2[10];
	//two pointer approch
	int j=n-1,i=0,k=0,l=i+1;
	while(l<j){
		if(arr[i]+arr[j]+arr[l]==s){
			arr2[k]=arr[j];
			arr2[k+1]=arr[i];
			arr2[k+2]=arr[l];
			arr[j]=INT_MIN;
			arr[i]=INT_MIN;
			arr[l]=INT_MIN;
			k=k+3;
			j--;
			i++;
			l++;
		}
		else if(arr[i]+arr[j]+arr[l]<s){
			i++;
			l++;	
		}
		else{
			j--;
		}
	} 
	for(i=0;i<k;i++)
		cout<<arr2[i]<<" ";
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
//	int arr[]={1,2,3,4,5,6,7,8,12};
	int k;
	cin>>k;
	cout<<"Bruteforce Approch"<<endl;
	bruteforce(arr,n,k);
	cout<<endl<<"Two Pointer Approch"<<endl;
	pair_sum(arr,n,k);
	return 0;
}
int bruteforce(int arr[],int n,int sum){
	int arr2[100];
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i]+arr[j]+arr[k]==sum){
					arr2[l]=arr[i];
					arr2[l+1]=arr[j];
					arr2[l+2]=arr[k];
					l=l+3;
					break;
				}
			}
		}
	}
	for(int i=0;i<l;i++)
		cout<<arr2[i]<<" ";
	return 0;
}
