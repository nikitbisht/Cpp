//Replce Space with @40
#include<iostream>
#include<string>
using namespace std;
void replace(string s1){
	string s2;
	for(int i=0;i<s1.length();i++){
		if(s1[i]==' '){
			s2.push_back('@');
			s2.push_back('4');
			s2.push_back('0');
		}
		else {
			s2.push_back(s1[i]);
		}
	}
	cout<<s1<<endl;
	cout<<s2<<endl;
}
int main(){
	string s1;
	getline(cin,s1);
	replace(s1);
	return 0;	
}