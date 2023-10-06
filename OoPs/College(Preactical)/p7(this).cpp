#include<iostream>
#include<string>
using namespace std;
class employee{
    public:
    string name;
    int age;
    int salary;

    void display(string name,int age,int salary){
        this->name=name;
        this->age=age;
        this->salary=salary;

         cout<<"Name:- "<<name<<endl;
         cout<<"Age:- "<<age<<endl;
         cout<<"Salary:- "<<salary<<endl;
    }
};
int main(){
    employee obj;
    obj.display("Nikit",20,500000);
    return 0;
}
