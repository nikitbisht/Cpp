//Factorial of nth number
#include<iostream>
using namespace std;
int fact(int n) {
	//base case
	if(n==0||n==1)
		return 1;
	return n*fact(n-1);
}
int main() {
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	cout<<fact(n)<<endl;
	return 0;
}