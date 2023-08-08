/*
Qn:- Binay to decimal
Ex:
n=101	decimal=5
n=1010	decimal=10
*/
#include<iostream>
#include<math.h>
using namespace std;
int decimal(int n){
	int ans=0,i=0;
	while(n!=0){
	if(n%10==1){
		ans=ans+pow(2,i);
	}
	i++;
	n=n/10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<decimal(n)<<endl;
	return 0;
}
