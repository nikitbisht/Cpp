#include<iostream>
using namespace std;
class Abc{
    public:
    static int a;
    int b=0;

    Abc(){
        a++;
        b++;
    }
    static void display(){
        cout<<a<<endl;
    }
};
int Abc::a=0;
int main(){
    Abc obj1;
    Abc obj2;
    Abc obj3;
    Abc obj4;
    Abc obj5;
    
    cout<<obj1.b<<endl;
    cout<<obj2.b<<endl;
    cout<<obj3.b<<endl;
    cout<<obj4.b<<endl;
    cout<<obj5.b<<endl;

    Abc::display();

    cout<<"a as static "<<Abc::a<<endl;
    return 0;
}