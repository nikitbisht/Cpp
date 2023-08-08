/*
Qn:- Compliment of base 10 integer
Ex:
n=5		binary=101		compliment=010		ans=2
n=10	binary=1010		compliment=0101		ans=5
*/
#include<iostream>
#include<math.h>
using namespace std;
int compliment(int n){
	int ans=0,mask=0;
	int m=n;
	while(m!=0){
		mask=(mask<<1)|1;
		m=m>>1;
	}
	ans=(~n)&mask;
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<compliment(n)<<endl;
	return 0;
}
