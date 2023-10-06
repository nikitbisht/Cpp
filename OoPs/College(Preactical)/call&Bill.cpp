#include<iostream>
#include<string>
using namespace std;
class Telecall{
    //data member
    public:
    int phno;
    string sname;
    int n;
    float amt;
    //Paramertize constructor
    Telecall(int phno,string sname,int n,float amt){
        this->phno=phno;
        this->sname=sname;
        this->n=n;
        this->amt=amt;
    }
    //Calculate phone bill
    void compute(){
        int d,n=this->n;
        amt=0;
        if(n>300){     //n=400
            d=n-300;        //d=100
            amt+=d*1.50;
            n=n-d;          //n=300
        }
        if(n>=201&&n<=300){     //n=300
            d=n-200;            //d=100
            amt+=d*1.20;
            n=n-d;              //n=200
        }
        if(n>=101&&n<=200){
            d=n-100;
            amt+=d*1.0;
            n=n-d;
        }
        if(n>=1&&n<=100){
            amt+=500;
        }
        if(n==0){
            amt=0;
        }
    }
    void display(){
        cout<<"Name:- "<<sname<<endl;
        cout<<"Number:- "<<phno<<endl;
        cout<<"Call dial "<<n<<endl;
        cout<<"Your BiLL is:- "<<amt<<endl;
    }
};
int main(){
    Telecall obj1(78946612,"Sanchit",400,0);
    obj1.compute();
    obj1.display();
}