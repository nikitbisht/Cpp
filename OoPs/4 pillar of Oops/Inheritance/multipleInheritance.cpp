/*
Multiple Inheritance:- when a class inherit more than one class.
single child class have multiple parents class
ex:- A -> C, B -> C
*/
#include<iostream>
using namespace std;
class human{
    public:
        int age;
        int weight;   
    public:
        void speak(){
            cout<<"Hello Hellow(human)"<<endl;
        }
};
class Dog{
    public:
        int biteforce;
        int attack;
    public:
        void bark(){
            cout<<"bhaw bhaw(DOG)"<<endl;
        }
};
class hybrid:public human,public Dog{

};
int main(){
    hybrid obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.attack<<endl;
    cout<<obj1.biteforce<<endl;
    obj1.speak();
    obj1.bark();
    return 0;
}