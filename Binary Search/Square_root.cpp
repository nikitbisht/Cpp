/*
Qn:- Find the Square root of a number
Ex:- n=25
O/p:- 5
*/
#include<iostream>
using namespace std;
//int decimal(int ,int ,int );
double decimal(int first,int precedence,int n){
	double factor=1;
	double ans=first;
	for(int i=0;i<precedence;i++){
		factor=factor/10;
		double j=ans;
		while(j*j<n){
			ans=j;
			j=j+factor;
		}
	}
	return ans;
}
int square_root(int n){
	int start=0;
	int end=n/2;
	long long int mid=start+(end-start)/2;
	int ans=0;
	while(start<=end){
		if(mid*mid==n){
			return mid;
		}
		else if(mid*mid<n){
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
	int first=square_root(n);
	double ans=decimal(first,3,n);
	cout<<ans<<endl;
	return 0;
}

