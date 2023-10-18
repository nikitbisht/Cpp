//Print Counting 1 to n
#include<iostream>
using namespace std;
//Tail Recursion
void print_1_to_N(int n) {
	//base case
	if(n==0)
		return ;
	cout<<n<<" ";
	print_1_to_N(n-1);
}

//Head Recursion
void print_N_to_1(int n) {
	//base case
	if(n==0)
		return ;
	print_N_to_1(n-1);
	cout<<n<<" ";
}
int main() {
	int n;
	cout<<"Enter the number:- "<<endl;
	cin>>n;
	print_1_to_N(n);
	cout<<endl;
	print_N_to_1(n);
	return 0;
}