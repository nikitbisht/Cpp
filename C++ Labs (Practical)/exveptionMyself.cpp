//Eception Handling
#include<iostream>
#include<string>
using namespace std;
int division(int x,int y){
	try{
		if(y==0){
			throw "EROOR KYA KRU";
		}
	}
	catch(const char* e){
		throw;	
	}
	return x/y;
}
int main(){
	int y = 0;
	int x = 15;
	double z =0;
	try{
		z = division(x,y);
	}
	catch(const char *e){
		cout<<"Exception occer"<<endl;
		cerr<<e;
	}
	cout<<z<<endl;
}