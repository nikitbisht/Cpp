//Add 2 array
//first focus on cases then code
#include<iostream>
using namespace std;
int main(){
	int n;
	int arr[100];
	int arr1[100];
	int arr2[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
		cin>>arr1[i];
	int j=k-1;
	int i=n-1;
	int carry=0;
	int l=0;
	while(i>=0&&j>=0){
		int sum=arr[i]+arr1[j]+carry;
		carry=sum/10;
		sum=sum%10;
		arr2[l]=sum;
		l++;
		j--;
		i--;
	}
	while(i>=0){
		int sum=arr[i]+carry;
		carry=sum/10;
		sum=sum%10;
		arr2[l]=sum;
		l++;
		i--;
	}
	while(j>=0){
		int sum=arr1[j]+carry;
		carry=sum/10;
		sum=sum%10;
		arr2[l]=sum;
		l++;
		j--;
	}
	if(carry!=0)
		arr2[l]=carry;
		
	for(int i=l;i>=0;i--)
		cout<<arr2[i]<<" ";
}
