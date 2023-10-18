//Say Digit
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
void Saydigit(string arr[],int n) {
	//base case
	if(n==0)
		return ;
	int digit=n%10;
	n=n/10;
	Saydigit(arr,n);
	cout<<arr[digit]<<" ";
}
int main() {
	int n;
	cout<<"Enter the value of n:- "<<endl;
	cin>>n;
	string arr[10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
	Saydigit(arr,n);
	return 0;
}