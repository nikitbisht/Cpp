#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //Create adjlist
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    key[1] = 0;

    for(int i=1; i<=n; i++){
        //find min in key
        int mini = INT_MAX;
        int minNode = -1;
        for(int j=1; j<=n; j++){
            if(mst[j] == false &&mini > key[j]){
                mini = key[j];
                minNode = j;
            }
        }
        
        mst[minNode] = true;

        for(auto neigh : adj[minNode]){
            if(mst[neigh.first] == false && key[neigh.first] > neigh.second){
                parent[neigh.first] = minNode;
                key[neigh.first] = neigh.second;
            }
        }

    }
    //store in ans
    vector<pair<pair<int,int>,int>> ans;
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;

}
