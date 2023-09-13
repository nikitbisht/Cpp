//Reference Variable
#include<iostream>
using namespace std;
void swapvalue(int &a,int &b){
	a=a+b;
	b=a-b;
	a=a-b;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<"Before Swap"<<endl;
	cout<<"A--> "<<a<<endl<<"B--> "<<b<<endl;
	swapvalue(a,b);
	cout<<"After Swap"<<endl;
	cout<<"A--> "<<a<<endl<<"B--> "<<b<<endl;
	return 0;
}