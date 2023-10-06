//Shallow copy store the reference of the object to the original memory address (both is using same memory)
//its only work in heap memory and dynamically work
#include<iostream>
#include<string.h>
using namespace std;
class Sallow{
    private:
    int health;
    char leve;

    public:
    char *name;
    //parameterize Constructor
    Sallow(int health,char leve,char name[]){
        this->name=new char[100];           // Allocate memory in heap
        this->health=health;
        this->leve=leve;
        strcpy(this->name,name);
    }
    //copy Constructor
    // Sallow(Sallow& temp){
    //     this->health=temp.health;
    //     this->leve=temp.leve;
    //     strcpy(this->name,temp.name);
    // }
    void display(){
        cout<<"name:- "<<this->name<<" Level:- "<<this->leve<<" Health:- "<<this->health<<endl;
    }
};
int main(){
    Sallow obj1(10,'c',"nikit");
    obj1.display();
    Sallow obj2(obj1);
    obj2.display();
    obj1.name[0]='H';
    obj1.display();
    obj2.display();
}