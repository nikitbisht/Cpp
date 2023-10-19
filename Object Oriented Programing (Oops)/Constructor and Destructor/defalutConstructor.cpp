#include<iostream>
using namespace std;
class hero{
    public:
    int health;
    char level;
//Constructor 
hero(){
    cout<<"Constructor Called"<<endl;
}
};
int main(){
    hero nikit;
    hero*niki=new hero;
    hero *n=new hero();
    
    /* when we create a object firstly it will call the constructor
    
    if we write "hero nikit" it will call "nikit.hero()"
    but in class there is no any hero fn because after complete class
    it will create constuctor automatically(dafault create)
   
    #if we write UDConstructor then the compiler/system made compiler
    will not be called.

    Constructor Properties   :
    1. it will envoke while object creation
    2. does not have return type 
    3. No input parameter
    */
   delete niki;
   delete n;
    return 0;
}