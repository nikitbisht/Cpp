/*
Multi-Level Inheritance:- when a class inheritance from a child and that child become a base class for new class.
there is more than 1 level
ex- A -> B -> C
*/
#include<iostream>
using namespace std;
class Animals{
    protected:
        int age;
        int weight;   
    public:
        void speak(){
            cout<<"Hello Hellow(ANIMALS)"<<endl;
        }
};
class Dog:public Animals{
    public:
        int attack;
    public:
        void bark(){
            cout<<"bhaw bhaw(DOG)"<<endl;
        }
};
class breed: public Dog{
    public:
        string name;
    public:
        void setage(int age){
           this->age=age;
        }
        int getage(){
            return this->age;
        }
        void setweight(int weight){
            this->weight=weight;
        }
        int getweight(){
            return this->weight;
        }
};

int main(){
    breed obj1;
    obj1.setage(10);
    obj1.setweight(56);
    cout<<obj1.getage()<<endl;
    cout<<obj1.getweight()<<endl;
    obj1.name="Bull dog";
    cout<<obj1.name<<endl;
    obj1.speak();
    obj1.bark();
    return 0;
}