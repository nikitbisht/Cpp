//Global Variable	(kabi use mt krna)
//insted global varible (for sharing variable) use reference variable(int&)
#include<iostream>
using namespace std;
int scope=15;			//Bad practice to use global variable 
void b();
void a(){
	cout<<"A fn:- "<<scope<<endl;
	scope++;
	b();
}
void b(){
	cout<<"B fn:- "<<scope<<endl;
	scope++;
}
int main(){
	cout<<"main:- "<<scope<<endl;
	scope++;
	a();
	cout<<"main:- "<<scope<<endl;
	return 0;	
}