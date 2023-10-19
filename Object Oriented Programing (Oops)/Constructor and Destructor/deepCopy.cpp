//Deep copy Entirely Different Memory
#include<iostream>
#include<string.h>
using namespace std;
class deep{
    private :
    int health;
    char level;

    public:
    char *name;
    //parameterize
    deep(int health,char level,char name[]){
        this->name=new char[100];           // Allocate memory in heap
        this->health=health;
        this->level=level;
        strcpy(this->name,name);
    }
    //Copy Constructor
    deep(deep &temp){
        char* ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
    }
    void display(){
        cout<<"name:- "<<this->name<<" Level:- "<<this->level<<" Health:- "<<this->health<<endl;
    }   
};
int main(){
    deep obj1(50,'A',"Nikit");
    deep obj2=obj1;
    obj1.display();
    obj2.display();
    obj1.name[0]='Z';
    obj1.display();
    obj2.display();
}