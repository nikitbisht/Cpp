//	GCD / HCF

#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	while(a!=b){
//		cout<<a<<" "<<b<<endl;
		if(a>b)
			a=a-b;
		else 
			b=b-a;
	}
	return a;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<"Hcf is: "<<gcd(a,b)<<endl;
}