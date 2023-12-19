//Find preticular word in file
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string str;
	fstream obj;
	obj.open("find.txt",ios::out);
	if(!obj)	cout<<"fail to open";
	printf("Etner the stirng:- ");
	getline(cin,str);
	obj<<str;
	obj.close();
	obj.open("find.txt",ios::in);
	char ch;
	int count =-1;
	while(!obj.eof()){
		obj>>ch;
		count++;
	}
	cout<<count<<endl;
	obj.close();
}