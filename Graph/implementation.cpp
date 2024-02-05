#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
	public:
		unordered_map<T,list<T>>adj;
		
	void addEdge(T u,T v,bool direction){
		//direction = 0 = undirected
		//direction = 1 = directed
		adj[u].push_back(v);
		if(!direction){
			adj[v].push_back(u);
		}
	}
	
	void printAdj(){
		for(auto i:adj){
			cout<<i.first<<"->";
			for(auto j:i.second){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
};
int main(){
	int n,m;
	cout<<"Enter the no of nodes:- "<<endl;
	cin>>n;
	cout<<"Enter the no of edges:- "<<endl;
	cin>>m;
	
	graph<int> g;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printAdj();
	return 0;
}
