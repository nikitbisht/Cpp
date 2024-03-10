#include<bits/stdc++.h>
void dfs(int node,int &timer,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,unordered_map<int,list<int>>&adj,vector<vector<int>>&result){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neigh:adj[node]){
        if(neigh == parent) continue;

        if(!visited[neigh]){
            dfs(neigh,timer,node,disc,low,visited,adj,result);
            //update low if there is backedge
            low[node] = min(low[node],low[neigh]);
            //bridge
            if(low[neigh] > disc[node]){
                result.push_back({neigh,node});
            }
        }else{
            //visited && != parent (back edge)
            low[node] = min(low[node],low[neigh]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
   //Create adj list 
   unordered_map<int,list<int>>adj;
   for(int i=0; i<edges.size(); i++){
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }

   int timer = 0;
   int parent = -1;
   vector<int>disc(v,-1);
   vector<int>low(v,-1);
   vector<bool>visited(v,false);
   vector<vector<int>>result;
   for(int i=0; i<v; i++){
       if(!visited[i]){
           dfs(i,timer,parent,disc,low,visited,adj,result);
       }
   }
   return result;

}
