/*
Hybrid inheritance:- its is a combination of more than one type of inheritance
ex:- Single + hierarchiecal = hierachiecal , Multiple , single
*/
#include<iostream>
using namespace std;
class A{
    public:
        int x;
    void a(){
        cout<<"i dont know"<<endl;
    }
};
class B:public A{
    public:
        int y;
    void b(){
        cout<<"b hai yrr"<<endl;
    }
};
class D{
    public:
        int z;
    void d(){
        cout<<"d hai yrr"<<endl;
    }
};
class C:public D,public A{
    public:
        int y;
    void d(){
        cout<<"d hai yrr"<<endl;
    }
};
int main(){
    C obj1;
    obj1.a();
    obj1.d();
    return 0;
}