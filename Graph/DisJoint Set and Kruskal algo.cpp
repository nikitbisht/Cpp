#include<algorithm>
void makeset(vector<int>&parent,vector<int>&rank,int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node,vector<int>&parent){
     //base case
    if(node == parent[node]){
        return node;
     }
    return parent[node] = findParent(parent[node],parent);
}

void unionset(int u,int v,vector<int>&parent , vector<int>& rank){
    u = findParent(u,parent);
    v = findParent(v,parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}
bool comp(vector<int>&a,vector<int>&b){
    return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int>parent(n);
  vector<int>rank(n);
  makeset(parent,rank,n);
  sort(edges.begin(),edges.end(),comp);
  int wt = 0;
  for(int i=0; i<edges.size(); i++){
      int u = findParent(edges[i][0],parent);
      int v = findParent(edges[i][1],parent);
      int wte = edges[i][2];

      if(u != v){
          unionset(u,v,parent,rank);
          wt += wte;
      }
  }
  return wt;
}
