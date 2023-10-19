#include<iostream>
#include<math.h>
using namespace std;
void primeOrNot(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cout<<n<<" is not prime no"<<endl;
			return ;
		}
	}
	cout<<n<<" is Prime number"<<endl;
}
int main(){
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	primeOrNot(n);
	return 0;
}