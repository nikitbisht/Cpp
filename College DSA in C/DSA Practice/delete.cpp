#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int partation(string& str,int start,int end){
    int mid = start+(end-start)/2;
    char key = str[mid];
    int s = start;
    int e = end;
    while(s<=e){
        while(str[s]<=key)
            s++;
        while(str[e]>key)
            e--;
        if(s<e){
            swap(str[s],str[e]);
        }
    }
    if(s>e){
        swap(str[mid],str[e]);
    }
    return e;
}

void quickSort(string& s,int start,int end){
    if(start>=end){
        return ;
    }
    int part = partation(s,start,end);
    quickSort(s,start,part-1);
    quickSort(s,part+1,end);
}
    
int main(){
	string str;
	int start = 0;
	cout<<"Enter the String:- "<<endl;
	getline(cin,str);
	cout<<str<<endl;
	int size = str.size();
	quickSort(str,start,size-1);
	cout<<str<<endl;
	return 0;
}