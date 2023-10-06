#include<iostream>
using namespace std;
class hero{
    //properties
    private:
        int health;
        int level;
    public:
    //Getter
        int gethealth(){
            return health;
        }
        char getlevel(){
            return level;
        }
    //Setter
        void sethealth(int h){
            health=h;
        }
        void setlevel(char ch){
            level=ch;
        }
};
int main(){
    //dynamically allocated
    hero*pika=new hero;
    pika->sethealth(95);
    (*pika).setlevel('A');
    cout<<"Health:- "<<pika->gethealth()<<endl;
    cout<<"Level:- "<<(*pika).getlevel()<<endl;
    delete pika;
    return 0;
}