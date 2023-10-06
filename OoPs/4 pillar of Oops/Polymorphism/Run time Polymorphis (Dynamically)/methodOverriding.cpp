/*
Function/Method Overriding:- it is a featur that allow you to redefine the parent class 
mehod in the child class based on their requirement.
*Rules:-
1. Same function Name
2. Same parameter
3. it is only possible in inheritance
*/
#include<iostream>
using namespace std;
class Animal{
    public:
        void speak(){
            cout<<"Speaking "<<endl;
        }
};
class dog: public Animal{
    public:
        void speak(){
            cout<<"Barking:"<<endl;
        }
};
int main(){
    Animal obj1;
    dog obj2;
    obj1.speak();
    obj2.speak();
    return 0;
}