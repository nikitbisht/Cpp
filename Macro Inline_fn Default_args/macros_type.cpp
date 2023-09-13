//Macros:- a pieace of code in a program that is replaced by value of macros
#include<iostream>
using namespace std;
#define DATE 31							//Object-like

#define instagram follower				//Chain-like

#define follower 38			
		
										//Multiline		
#define ELE 1,\
			2,\
			3
			
#define min(a,b) (((a)<(b))?(a):(b))	//Function-like

int main(){
	
	//object like macros
	cout<<"Object like Macros"<<endl;
	cout<<"today is "<<DATE<<"/aug/2023"<<endl<<endl;;
	
	
	//chain macros
	cout<<"Chain Macros"<<endl;
	cout<<"i have "<<instagram<<"k follower"<<endl<<endl;;
	
	
	//Multi-line macros
	cout<<"Multi-line Macros"<<endl;
	int arr[]={ELE};
	for(int i=0;i<3;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<endl;
	
	
	//Function Like Macros
	cout<<"Function Like Macros"<<endl;
	int a=10,b=20;
	cout<<min(a,b)<<endl;
	return 0;
}