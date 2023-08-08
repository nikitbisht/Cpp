/*
Qn:- given number n find the number of 1 present in its binary form
Ex:
n=5		binary= 101		result= 2
*/
#include<iostream>
using namespace std;
int binary(int n){
	int count=0;
	while(n!=0){
	if(n&1==1)
		count++;
	n=n>>1;
	}
	return count;
}
int main(){
	int n,result=0;
	cin>>n;
	cout<<binary(n)<<endl;
	return 0;
}
/*
Dryrun
n=5		binary=101		1&1==1		count++		n>>1	10
n=2		binary=10		0&1==1		n>>1	1
n=1		binary=1		1&1==1		n>>1	0
n=0 	return count
*/
