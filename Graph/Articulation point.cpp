//Articulation point in Graph
#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
void dfs(int node,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,vector<int>&ap,unordered_map<int,list<int>>&adj,int &timer){
	visited[node] = true;
	disc[node] = low[node] = timer++;
	int child = 0;
	
	for(auto neigh : adj[node]){
		//same node come from
		if(neigh == parent) continue;
		if(!visited[neigh]){
			dfs(neigh,node,disc,low,visited,ap,adj,timer);
			low[node] = min(low[node],low[neigh]);
			
			//check Articulation point
			if(low[neigh] >= disc[node] && parent != -1){
				ap[node] = true;
			}
			child++;
		}else{
			//back edge
			low[node] = min(low[node],disc[neigh]);
		}
	}
	
	if(child > 1 && parent == -1){
		ap[node] = 1;
	}
}
int main(){
	int n = 5;
	vector<pair<int,int>>edges;
	edges.push_back({0,3});
	edges.push_back({0,1});
	edges.push_back({0,4});
	edges.push_back({3,4});
	edges.push_back({1,2});
	unordered_map<int,list<int>>adj;
	//Create adjlist
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);		
	}
	
	//data structure
	vector<int>disc(n,-1);
	vector<int>low(n,-1);
	vector<bool>visited(n,false);
	vector<int>ap(n,0);
	int timer = 0;
	
	for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(i,-1,disc,low,visited,ap,adj,timer);
		}
	}
	cout<<"Articulation point :- ";
	for(int i=0; i<n; i++){
		if(ap[i] > 0)
			cout<<i<<" ";
	}
  return 0;
}
