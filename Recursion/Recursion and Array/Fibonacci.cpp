//Fibonacci of nth number
#include<iostream>
using namespace std;
int fibo(int n) {
	//base cases
	if(n==0||n==1)								//if(n==2||n==1) for if you want to start fibonacci series from 1st term
		return n;
	return fibo(n-1)+fibo(n-2);
}
int main() {
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	cout<<fibo(n)<<endl;
	return 0;
}