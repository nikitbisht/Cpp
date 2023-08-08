/*
Qn:- given number n find its product and sum of each then subcrat is sum with porduct
Ex:
n=234	product=24	sum=9	result= 24-9 =15
*/
#include<iostream>
using namespace std;
int main(){
	int n,result=0,product=1,sum=0;
	cin>>n;
	while(n!=0){
		int d=n%10;
		product=product*d;
		sum+=d;
		n=n/10;
	}
	result=product-sum;
	cout<<result<<endl;
	return 0;
}
