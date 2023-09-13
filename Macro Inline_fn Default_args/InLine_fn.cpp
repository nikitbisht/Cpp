//INLINE fn
/*
it is use to reduce the fn call overhead (reduce fn calling and returning time)
function body
	1 line --> compiler is ready to inline it
	2-3 line --> it's compiler choise to inline it or not
	>3 line--> compiler is not ready to inline it
Benefits:
	not extra memory usage
	not fn call overhead
*fn call replace with its body

*/
#include<iostream>
using namespace std;
inline int getmax(int a,int b){
	return (a>b)?a:b;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<getmax(a,b)<<endl;
	return 0;
}