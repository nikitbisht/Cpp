/*
Qn:- Find nCr where n and r are input and find nCr=n!/r!*(n-r)!
Ex:
n=8	r=3		output= 56
*/
#include<iostream>
#include<math.h>
using namespace std;
int fact(int n){
	int fact=1;
	for(int i=1;i<=n;i++)
		fact =fact*i;
	return fact;
}
int ncr(int n, int r){
	int numi=fact(n);
	int demo=fact(r)*fact(n-r);
	int ans=numi/demo;
	return ans;
}
int main(){
	int n,r;
	cin>>n>>r;
	cout<<ncr(n,r)<<endl;
	return 0;
}
