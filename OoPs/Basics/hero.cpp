#include<iostream>
#include "hero1.cpp"
using namespace std;
int main(){
    pokemon p1;
    cin>>p1.name;
    cin>>p1.health;
    cin>>p1.ch;
    // cout<<"Size of p1 :- "<<sizeof(p1)<<endl;
    cout<<"Name is:- "<<p1.name<<endl;
    cout<<"Health:- "<<p1.health<<endl;
    cout<<"Leve is:- "<<p1.ch<<endl;
}