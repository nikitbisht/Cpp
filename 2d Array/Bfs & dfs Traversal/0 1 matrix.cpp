class Solution {
private:
    bool isValid(int nrow,int ncol,int n,int m,vector<vector<bool>>& visited,vector<vector<int>>& mat){
        return (nrow < n && nrow >=0 && ncol < m && ncol >=0 && !visited[nrow][ncol] && mat[nrow][ncol] == 1);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            dist[row][col] = dis;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(isValid(nrow,ncol,n,m,visited,mat)){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }

        return dist;

    }
};
