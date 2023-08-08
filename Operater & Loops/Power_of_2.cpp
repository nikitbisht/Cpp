/*
Qn:- check the number is power of 2 or not
Ex:
n=16	2^4		Ture
n=14	False
*/
#include<iostream>
#include<math.h>
using namespace std;
int compliment(int n){
	int count=0;
	bool ans=false;
	if(n==1)
		return ans;
	while(n!=0){
		if(n&1==1)
			count++;
		n=n>>1;
	}
	if(count==1)
		ans=true;
	return ans;
}
int main(){
	int n;
	cin>>n;
	bool ans=compliment(n);
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}
