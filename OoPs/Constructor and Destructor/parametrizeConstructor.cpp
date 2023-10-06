#include<iostream>
using namespace std;
class hero{
    public:
    int health;
    char level;
hero(int health,int level){   // Nearest scope
    // health=health;   //the both health are which has nearest scope (variable scoping )
    this->health=health; //this is keyword used to store address of curren object
    this->level=level;
    cout<<"this "<<this<<endl;
}
    void print(){
        cout<<health<<endl;
        cout<<level<<endl;
    }
};
 //if we write any constructor implementation then the default consturctor(compiler/system made) will remove or deleted,they didnot exist.
int main(){
    hero nikit(55,'A');
    cout<<"Address of nikit "<<&nikit<<endl;
    nikit.print();
}