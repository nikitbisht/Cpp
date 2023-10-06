#include<iostream>
using namespace std;
class hero{
    //properties
    private:
    int health;
    char level;
    public:
    //getter
    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    //setter
    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }
};
int main(){
    hero pikachu;
    char ch;
    int heal;
    cout<<"Enter the health of pickachu:- "<<endl;
    cin>>heal;
    cout<<"Enter the level of pikachu:- "<<endl;
    cin>>ch;
    pikachu.sethealth(heal);
    pikachu.setlevel(ch);
    cout<<"health:- "<<pikachu.gethealth()<<endl;
    cout<<"Level:- "<<pikachu.getlevel()<<endl;
    return 0;
}