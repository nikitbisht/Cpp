//Default Argument and its restriction
#include<iostream>
using namespace std;
void add(int a, float b=1.2){
	cout<<"a:- "<<a<<endl;
	cout<<"b:- "<<b<<endl;
}
int main(){
	int a;
	float b;
	cout<<"Enter the value of a:- "<<endl;
	cin>>a;
	cout<<"Enter the value of b:- "<<endl;
	cin>>b;
	cout<<endl;
	cout<<"When Pass both a and b in function"<<endl;
	add(a,b);
	cout<<"When Pass only b in function"<<endl;
	add(b);
	return 0;
}