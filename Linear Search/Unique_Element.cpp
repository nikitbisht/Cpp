/*
Qn:- Find Unique element where size of array n=2m+1 where m= twice,1 are unique
Ex:
n=7
arr[]={6,2,3,1,3,6,2}
ans=1
*/
#include<iostream>
using namespace std;
int unique(int arr[],int n){
	int ans=0;
	for(int i=0;i<n;i++)
		ans=ans^arr[i];
	return ans;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int ans=unique(arr,n);
	cout<<ans<<endl;
	return 0;
}
/*
Operates
&	and	
|	or
~	not
^	xor
*/
