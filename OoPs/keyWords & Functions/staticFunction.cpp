/*      STATIC FUNCTION
1. No need of object creation.
2. No any "this" key word (because this keyword pointer to current object and as we know that by point no 1)
3. It Only access Static member

*/
#include<iostream>
using namespace std;
class hero{
    public:
    int x;
    int y;
    static int timeToComplete;

    
    static int random(){
        // cout<<this->x<<endl;            //error
        // cout<<x<<endl;                 //error
        cout<<timeToComplete<<endl;
    }
};
int hero :: timeToComplete=10;
int main(){
    hero h1;
    h1.random();
    return 0;
}