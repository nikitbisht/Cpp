#include<iostream>
using namespace std;
class A{
	public:
		int a;
		
	void display(){
		cout<<"Class A"<<endl;
	}
};
class B: virtual public A{};
class C: virtual public A{};
class D:public B,public C{};

int main(){
	D obj1;
	obj1.display();
	return 0;
}