/*
Qn:- decimal to binary
Ex:
n=5		binary= 101	
n=7		binary=111
*/
#include<iostream>
#include<math.h>
using namespace std;
int binary(int n){
	int temp=0,ans=0,i=0;
	while(n!=0){
	temp=n&1;
	ans=(temp*pow(10,i))+ans;
	n=n>>1;
	i++;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<binary(n)<<endl;
	return 0;
}
