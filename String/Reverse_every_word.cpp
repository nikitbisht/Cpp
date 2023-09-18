/*
Qn:- Reverse every word in string
my name is nikit
ym eman si tikin
*/
#include<iostream>
using namespace std;
int reverse(char s[],int index,int last){
	while(index<=last) {
		swap(s[index++],s[last--]);
	}
	return 0;
}
void reverseMyword(char s[]){
	int index=0;
	for(int last=0;last<=strlen(s);last++){
		if(s[last]==' '||s[last]=='\0'){
			reverse(s,index,last-1);
			index=last+1;
		}
	}
}
int main(){
	char s[100];
	cin.getline(s,100);
	reverseMyword(s);
	cout<<s<<endl;
	return 0;
}