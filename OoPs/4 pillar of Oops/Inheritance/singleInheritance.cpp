/* 
Single- when one class extend the functionally of another class.
ex:- A -> B 
*/
#include<iostream>
#include"single.cpp"
using namespace std;
int main(){
    Dog obj1;
    obj1.setage(10);
    obj1.setweight(56);
    cout<<obj1.getage()<<endl;
    cout<<obj1.getweight()<<endl;
    obj1.breed="German Sherpread";
    cout<<obj1.breed<<endl;
    return 0;
}