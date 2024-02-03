class Solution {
private:
    void addSolution(int n,vector<vector<char>>&board,vector<vector<string>>& ans){
        vector<string>temp;
        for(int i=0; i<n; i++){
            string str;
            for(int j=0; j<n; j++){
                str.push_back(board[i][j]);
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,int n,vector<vector<char>> &board){
        //check for left
        int j = col;
        while(j >= 0)
            if(board[row][j--]=='Q') return false;

        //check for upper left
        int i = row;
        j = col;
        while(i >= 0 && j >= 0)
            if(board[i--][j--] == 'Q') return false;
   
        //check for down left
        i = row;
        j = col;

        while(i < n && j >= 0)
            if(board[i++][j--] == 'Q') return false;

        return true;
    }
    void chess(int col,int n,vector<vector<char>> &board,vector<vector<string>> & ans){
      //base case  
      if(col == n){
            addSolution(n,board,ans);
            return ;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                chess(col+1,n,board,ans);
              //backtrack
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        chess(0,n,board,ans);
        return ans;
    }
};
