// work in progress
#include<iostream>
using namespace std;
int countChoclate(int wrapper,int choclate,int ans){
    //base case
    if(choclate<=1){
        return ans;
    }
    // choclate=wrapper%2;
    ans+=wrapper;
    choclate=wrapper/2;
    wrapper=0;
    return countChoclate(wrapper,choclate,ans);
}
int main(){
    int wrapper;
    int money;
    int price;
    cout<<"Enter the Money "<<endl;
    cin>>money;
    cout<<"Enter the Price of choclate "<<endl;
    cin>>price;
    cout<<"Enter the wrapper "<<endl;
    cin>>wrapper;
    int choclate=money/price;
    cout<<countChoclate(wrapper,choclate,0)<<endl;
    return 0;
}