#include <bits/stdc++.h>
void dfs(int node, vector<int>&visited,unordered_map<int,list<int>>&adj,stack<int>&st){
	visited[node]= true;
	for(auto neigh : adj[node]){
		if(!visited[neigh])
			dfs(neigh, visited, adj, st);
	}
	st.push(node);
}
void revdfs(int node, vector<int>&visited,unordered_map<int,list<int>>&adj){
	visited[node]= true;
	for(auto neigh : adj[node]){
		if(!visited[neigh])
			revdfs(neigh, visited, adj);
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
	//create a adjacency list
	unordered_map<int,list<int>>adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}
	//topological Sort
	vector<int>visited(v,false);
	stack<int>st;
	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfs(i,visited,adj,st);
		}
	}
	//Transpose adj
	unordered_map<int,list<int>>trasadj;
	for(int i=0; i<v; i++){
		visited[i] = false;
		for(auto neigh : adj[i]){
			trasadj[neigh].push_back(i);
		}
	}
	int count = 0;
	//do dfs
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!visited[top]){
			revdfs(top, visited, trasadj);
			count++;
		}
	}
	return count;
}
