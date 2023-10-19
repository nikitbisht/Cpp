#include<iostream>
#include<string>
using namespace std;
class eleBill{
	private:
		string name;
		int unit;
		float bill;
	public:
		void compute(){
			bill=0;
			int rem=0;
			int unit =this->unit;
			if(unit>300){
				rem=unit-300;
				bill+=rem*90;
				unit=unit-rem;
			}
			if(unit<=300&&unit>100){
				rem=unit-100;
				bill+=rem*80;
				unit=unit-rem;
			}
			if(unit>=1&&unit<=100){
				bill+=unit*60;
			}
			//convet paisa into rupees
			bill=bill/100;
			if(bill>300){
				bill+=50;
			}
			// 15 precent of bill
			float avg=bill*15/100;
			bill+=avg;
			this->bill=bill;
		}
	void display(){
		cout<<"Name:- "<<this->name<<endl;
		cout<<"Unit:- "<<this->unit<<endl;
		cout<<"Bill:- "<<this->bill<<endl;
	}
	eleBill(string s1,int unit,int bill){
		this->name=s1;
		this->unit=unit;
		this->bill=bill;
	}
};
int main(){
	string str;
	getline(cin,str);
	cout<<str<<endl;
	eleBill obj1("nikit",500,0);
	obj1.compute();
	obj1.display();
	return 0;
}