#include<iostream>
using namespace std;
class sample{
    private:
    int a;
    int b;
    int c;
    
    public:
    //default Constructor
    sample(){
        a=10;
        b=10;
        c=10;
    }
    //Parameterize Constructor
    sample(int a,int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    //Copy Constructor
    sample(sample &obj){
        this->a=obj.a;
        this->b=obj.b;
        this->c=obj.c;
    }
    void display(){
        cout<<"a:- "<<a<<endl;
        cout<<"b:- "<<b<<endl;
        cout<<"c:- "<<c<<endl;
    }
};
int main(){
    sample obj1;
    sample obj2(2,5,10);
    sample obj3(obj2);
    cout<<"Obj1 Elements:- "<<endl;
    obj1.display();
    cout<<"Obj2 Elements:-"<<endl;
    obj2.display();
    cout<<"Obj3 Elements:-"<<endl;
    obj3.display();
    return 0;
}