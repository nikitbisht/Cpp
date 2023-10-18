//Cout way to reach the nth stair
#include<iostream>
using namespace std;
int coutWay(int n) {
	//base case
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	return coutWay(n-1)+coutWay(n-2);
}
int main() {
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	cout<<"The Way to reach nth stair is:- "<<coutWay(n)<<endl;
	return 0;
}