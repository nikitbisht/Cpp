#include<iostream>
#include<string>
using namespace std;
class employee{
    public:
    string name;
    int age;
    int salary;

    void display(string name1,int age1,int salary1){
        name=name1;
        age=age1;
        salary=salary1;

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
