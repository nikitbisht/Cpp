/*
Operator Overloading:- 
*/
#include<iostream>
using namespace std;
class A{
    public:
        int a;
        int b;

        int operator+(A&obj){
            int value1=this->a;
            int value2= obj.a;
            return value2-value1;
        }
};
int main(){
    A obj1,obj2;
    obj1.a=12;
    obj2.a=95;
    cout<<obj1+obj2<<endl;
    return 0;
}