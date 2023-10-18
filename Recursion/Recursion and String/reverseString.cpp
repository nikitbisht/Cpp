//Reverse String through Recursion 
#include<iostream>
#include<string.h>
using namespace std;
//Two Pointer Approch
void reverse(string &str,int i,int j){
	//base case
	if(i>j)
		return ;
	//Processing
	swap(str[i],str[j]);
	
	//Recursion Call
	return reverse(str,i+1,j-1);
}
int main(){
	string str;
	cout<<"Enter the String:- "<<endl;
	cin>>str;
	reverse(str,0,str.length()-1);
	cout<<str<<endl;
}