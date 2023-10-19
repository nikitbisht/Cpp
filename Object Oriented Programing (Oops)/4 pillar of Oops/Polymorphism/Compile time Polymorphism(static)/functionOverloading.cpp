/*
Function Overloading;-  if we want to make many function of same name.
to solve this problem we can cange in input Argument
1. change in number
2. change in type
*/
#include<iostream>
using namespace std;
class A{
    public:
        void sayhello(){
            cout<<"Hy Uttarakhand"<<endl;
        }
        //change in type
        void sayhello(string s2,int n){
            cout<<"Change in type"<<endl;
        }
        int sayhello(string s1){
            cout<<"hello "<<s1<<endl;
            return -1;
        }

};
int main(){
    A obj1;
    obj1.sayhello("moto");
    obj1.sayhello("moto",95);
    obj1.sayhello();
    return 0;
}