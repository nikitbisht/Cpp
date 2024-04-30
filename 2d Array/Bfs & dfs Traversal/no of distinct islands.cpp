//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited,
    int*delrow,int*delcol,int n,int m,vector<pair<int,int>> &v,int brow,int bcol){
        //base - current
        v.push_back({row-brow,col-bcol});
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol] && !visited[nrow][ncol]){
                dfs(nrow,ncol,grid,visited,delrow,delcol,n,m,v,brow,bcol);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,visited,delrow,delcol,n,m,v,i,j);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
