/*
Qn:- Find the sum of all element in the array
Ex:
arr[]={4,12,8,10}
ans=34
*/
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,sum=0;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		sum=sum+arr[i];
	cout<<"sum:- "<<sum<<endl;
	return 0;
}
