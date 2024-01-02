#include<iostream>
using namespace std;
class sample{
	public:
		int data;
	void sayhello(int data){
		this->data = data;
	}
	friend sample operator*(sample & obj1,sample & obj2);
};

sample operator*(sample & obj1,sample &obj2){
		sample obj3;
		obj3.data = obj1.data + obj2.data;
		return obj3;
}
	
int main(){
	sample obj1;
	sample obj2;
	sample obj3;
	obj1.sayhello(50);
	obj2.sayhello(10);
	obj3 = obj1*obj2;
	cout<<obj3.data<<endl;
	return 0;
}