/*
Inheritance Amiguity:- if a class inherit more than one base class and inside those base class have same function name,
and if want to access then what class function is called?
to solve this problem we hace Scope Resolution Operator(::) 
object_name     class_name      ::      function_name();

*/
#include<iostream>
using namespace std;
class A{
    public:
        void area(){
            cout<<"Area of class A"<<endl;;
        }
};
class B{
    public:
        void area(){
            cout<<"Area of class B"<<endl;
        }
};
int main(){
    A obj1;
    B obj2;

    // obj1.area();
    obj1.A::area();
    obj2.B::area();
    // obj1.area();
    return 0;
}