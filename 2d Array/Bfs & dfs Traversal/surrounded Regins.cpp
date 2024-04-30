class Solution {
private:

    bool isValid(int row,int col,int n,int m,vector<vector<char>>& board,vector<vector<bool>>& visited){
        return (row<n && row>=0 && col<m && col>=0 && board[row][col]=='O' && !visited[row][col]);
    }



    void dfs(int row,int col,int &n,int &m,vector<vector<char>>& board,vector<vector<bool>>& visited,vector<int>&dlrow,vector<int>&dlcol){


        visited[row][col] = 1;


        for(int i=0; i<4; i++){
            int nrow = row + dlrow[i];
            int ncol = col + dlcol[i];
            if(isValid(nrow,ncol,n,m,board,visited)){
                dfs(nrow,ncol,n,m,board,visited,dlrow,dlcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<int>dlrow = {-1,0,1,0};
        vector<int>dlcol = {0,-1,0,1};

        //first row and last row
        for(int i=0; i<m; i++){
            //first row
            if(!visited[0][i]&&board[0][i] == 'O'){
                dfs(0,i,n,m,board,visited,dlrow,dlcol);
            }

            //first row
            if(!visited[n-1][i]&&board[n-1][i] == 'O'){
                dfs(n-1,i,n,m,board,visited,dlrow,dlcol);
            }
        }

        //first col and last col
        for(int i=0; i<n; i++){
            if(!visited[i][0]&&board[i][0] == 'O'){
                dfs(i,0,n,m,board,visited,dlrow,dlcol);
            }

            if(!visited[i][m-1]&&board[i][m-1] == 'O'){
                dfs(i,m-1,n,m,board,visited,dlrow,dlcol);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
