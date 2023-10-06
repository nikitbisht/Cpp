#include<iostream>
using namespace std;
class Animals{
    protected:
        int age;
        int weight;   
    public:
        void speak(){
            cout<<"Hello Hellow"<<endl;
        }
};
class Dog:public Animals{
    public:
        string breed;
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
