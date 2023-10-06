//p13 postfix and prefix operator overloading
#include<iostream>
using namespace std;
class box{
    private:
    int a;
    
    public:
    box(){
        a=10;
    }
    //perfix
    box operator++(){
    	box obj;
    	obj.a=obj.a+10;
    	return obj;
	}
	//postfix
	box operator++(int ){
		box obj;
		obj.a=obj.a+20;
		return obj;
	}
    void display(){
    	cout<<"a:= "<<this->a <<endl;
	}
    
};
int main(){
    box obj1;
	box obj2=++(obj1);
	obj2.display();
	
	box obj3=(obj2)++;
	obj3.display();
    return 0;
}