//Using Heap Memory
#include<iostream>
using namespace std;
inline int getmax(int *a,int* b){
	return (*a>*b)?*a:*b;
}
/*
inline int getmax(int &a,int& b){
	return (a>b)?a:b;
}
*/
int main(){
	int *a=new int;
	int *b=new int;
	cin>>*a>>*b;
	cout<<getmax(a,b)<<endl;
//	cout<<getmax(*a,*b)<<endl;
	delete a;
	delete b;
	return 0;
}