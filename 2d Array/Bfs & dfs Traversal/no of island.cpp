class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited,int& n,int &m){
        visited[row][col] = 1;
        //Top
        if(row-1 >=0 && grid[row-1][col] == '1' && !visited[row-1][col]){
            visited[row-1][col] = 1;
            dfs(row-1,col,grid,visited,n,m);
        }
        //left
        if(col-1 >=0 && grid[row][col-1] == '1' && !visited[row][col-1]){
            visited[row][col-1] = 1;
            dfs(row,col-1,grid,visited,n,m);
        }
        //bottom
        if(row+1 < n && grid[row+1][col] == '1' && !visited[row+1][col]){
            visited[row+1][col] = 1;
            dfs(row+1,col,grid,visited,n,m);
        }
        //right
        if(col+1 < m && grid[row][col+1] == '1' && !visited[row][col+1]){
            visited[row][col+1] = 1;
            dfs(row,col+1,grid,visited,n,m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,visited,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
