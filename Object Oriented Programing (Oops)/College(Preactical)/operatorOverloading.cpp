#include<iostream>
#include<string>
using namespace std;
string operator+(string s1,int a){
    string s2=to_string(a);
    return s1+s2;
}
int main(){
    string s1="hello ";
    string s2="world";
    string s3=s1+s2;
    cout<<"S3:- "<<s3<<endl;
    int a=10;
    int b=10;
    int c=a+b;
    cout<<"c:- "<<c<<endl;
    string s4=s1+a;
    cout<<"S4:- "<<s4<<endl;
    return 0;
}