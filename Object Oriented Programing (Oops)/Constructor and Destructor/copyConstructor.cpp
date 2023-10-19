#include<iostream>
using namespace std;
class hero{
    public:
    int health;
    char level;
//parametrize constructor
hero(int health,int level){ 
    this->health=health; 
    this->level=level;
}
//copy Constructor
hero(hero& temp){
    cout<<"Copy Constructor call "<<endl;
    this->health=temp.health;
    this->level=temp.level;
}
    void print(){
        cout<<health<<endl;
        cout<<level<<endl;
    }
};
 //if we write any constructor implementation then the default consturctor(compiler/system made) will remove or deleted,they didnot exist.
int main(){
    hero suresh(55,'A');
    
//Copy Constructor Calling
    hero ritesh(suresh);
    /*  ritesh.health=suresh.health;
        ritesh.level=suresh.level;      */
    ritesh.print();
    return 0;
}