/*Destructor:- While object goes out of scope it will call destructor to deallocate memory
Dynamica Allocation: The compiler didn't call the destructor automatically its our duty to call compiler manually with delete fn;
*/
#include<iostream>
using namespace std;
class hero{
    private:
    int x;
    int y;

    public:
    ~hero(){
        cout<<"Destructor Called"<<endl;
    }
};
int main(){
    //static allocation
    hero h1;

    hero* h2=new hero;
    delete h2;      //manually destructor call
    return 0;
}