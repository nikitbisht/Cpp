#include<set>
#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //Creating  adj lsit
    unordered_map<int,list<pair<int,int>>>adj;   
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create distance array:
    vector<int>dist(vertices,INT_MAX);
    dist[source] = 0;
    //Create set
    set<pair<int,int>> st;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDesti = top.first;
        int node = top.second;
        st.erase(st.begin());

        for(auto neigh : adj[node]){
            if(nodeDesti + neigh.second < dist[neigh.first]){
                //if recorde present
                auto recorde = st.find(make_pair(dist[neigh.first],neigh.first));
                if(recorde != st.end()){
                    st.erase(recorde);
                }
                //update distance
                dist[neigh.first] = nodeDesti + neigh.second;
                //record push
                st.insert(make_pair(dist[neigh.first],neigh.first));
            }
        }
    }
    return dist;
}
