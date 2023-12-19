//Eception Handling
#include<iostream>
using namespace std;
int main(){
	int y = 0;
	int x = 15;
	double z ;
	try{
		if(y==0){
			throw runtime_error("math error");
		}
		z=x/y;
	}
	catch(runtime_error &e){
		cout<<"Exception occer"<<endl;
		cout<<e.what();
	}
}