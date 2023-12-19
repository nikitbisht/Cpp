//File Handling in c++
/*
1. ios::out 	write in file
2. ios::in		read fornt frile
3. ios::app     append into file

noskipws ch

*/
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
	string str;
	fstream obj;
	obj.open("Nikit.txt",ios::out);
	if(!obj){
		cout<<"Failed to open the file"<<endl;
	}
	cout<<"Enter the string:- "<<endl;
	getline(cin,str);
	obj<<str;
	obj.close();
	// create a new file
	fstream temp;
	obj.open("Nikit.txt",ios::in);
	temp.open("copy.txt",ios::out);
	if(!temp){
		cout<<"File creation unsuccesfull";
	}
	string s;
	int cnt = 0;
	while(!obj.eof()){
		obj>>s;
		temp<<s;
		temp<<' ';
	}
	obj.close();
	temp.close();
	return 0;
}