#include<iostream>
#include<string>
using namespace std;
class student{
    public:
    string name;
    int age;
    char section;
    int marks;
    string college;

    void setvalue(string name1,int age1,char section1,int marks1,string college1){
        name=name1;
        age=age1;
        section=section1;
        marks=marks1;
        college=college1;
    }
};
int main(){
    student arr[4];
    arr[0].setvalue("nikit",20,'A',95,"gehu");
    arr[1].setvalue("nikit",20,'A',55,"gehu");
    arr[2].setvalue("nikit",20,'A',67,"gehu");
    arr[3].setvalue("nikit",20,'A',34,"gehu");
    int avg=(arr[0].marks+arr[1].marks+arr[2].marks+arr[3].marks)/4;
    cout<<"Avegrage:- "<<avg<<endl;
    return 0;
}