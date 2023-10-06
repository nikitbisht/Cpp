/*
Hierarchical Inheritance:- one class server as parent for more than one child/derived clas
ex;-                     -------A--------
                    ----B----       ----C----
                    D       E       F       G
*/
#include<iostream>
using namespace std;
class Animals{
    public:
        int age;
        int height;
    public:
        void speak(){
            cout<<"bla bla bla"<<endl;
        }
};
class dog:public Animals{
    private:
        int biteforce;
    public:
        void setbitforce(int x){
            this->biteforce=x;
        }
        int getbitforce(){
            return this->biteforce;
        }
        void bark(){
            cout<<"Bhau bhau"<<endl;
        }
};
class cat: public Animals{
    private:
        int powerBlackMagic;
    public:
        void setpower(int x){
            this->powerBlackMagic=x;
        }
        int getpower(){
            return this->powerBlackMagic;
        }
        void meow(){
            cout<<"meow meow"<<endl;
        }
};
int main(){
    Animals obj1;
    dog obj2;
    cat obj3;
    cout<<obj1.age<<endl;
    obj1.speak();

    obj2.setbitforce(700);
    cout<<obj2.getbitforce()<<endl;
    obj2.bark();

    obj3.setpower(92);
    cout<<obj3.getpower()<<endl;
    obj3.meow();
    return 0;
}
