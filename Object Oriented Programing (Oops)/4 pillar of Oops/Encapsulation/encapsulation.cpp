/*
Encapsulation:- to wrapping up data members and member function (Data hiding)
if all the data member are marked as private known as FUlly Encapsulated class
*/
#include<iostream>
#include<string>
using namespace std;
class student{
    private:
        string name;
        int age;
        int weight;
        int height;
    public:
    student(){

    }
    //Parametrize consturctor
    student(string name,int age,int weight,int height){
        this->name=name;
        this->age=age;
        this->weight=weight;
        this->height=height;
    }
    int getage(){
        return this->age;
    }
};
int main(){
    student obj1("Nikit",19,65,5);
    cout<<obj1.getage()<<endl;
    return 0;
}