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
	string s,e;
	cout<<"Find word"<<endl;
	cin>>e;
	while(!obj.eof()){
		obj>>s;
		if(s==e)
			cout<<"present"<<endl;
	}
	obj.close();
}