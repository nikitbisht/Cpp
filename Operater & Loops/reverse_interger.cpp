/*
Qn:- Reverse Integer
Ex:
n=1234	ans=4321
n=195	ans=591
sp n=1289548999	ans=9998459812
*/
#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
int reverse(int n){
	int ans=0,i=0;
	while(n!=0){
	i=n%10;
	if(ans>INT_MAX/10||ans<INT_MIN/10)
		return ans;
	ans=(ans*10)+i;
	n=n/10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<reverse(n)<<endl;
	return 0;
}
