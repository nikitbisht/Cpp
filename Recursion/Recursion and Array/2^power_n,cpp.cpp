// 2 raise to power of n
#include<iostream>
using namespace std;
int power(int n){
	//base case
	if(n==0)
		return 1;
	return 2*power(n-1);
}
int main(){
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	cout<<power(n)<<endl;
	return 0;
}