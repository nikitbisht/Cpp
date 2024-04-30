class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        int time = 0;
        int empt=0;
        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else{
                    if(grid[i][j] == 0){
                        empt++;
                    }
                    visited[i][j]=0;
                }
            }
        }
        if(empt == m*n) return 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int nrow = q.front().first;
                int ncol = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int neiRow = nrow+drow[i];
                    int neiCol = ncol+dcol[i];
                    if(neiRow >= 0 && neiRow < n && neiCol >= 0 && neiCol < m && grid[neiRow][neiCol] == 1 && visited[neiRow][neiCol] !=2){
                        q.push({neiRow,neiCol});
                        visited[neiRow][neiCol] = 2;
                    }
                }
            }
            time++;
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }
        return time-1;

    }
};
