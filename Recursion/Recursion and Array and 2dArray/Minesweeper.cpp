class Solution {
private:
    int countMine(int x,int y,vector<vector<char>>&board){
        int cnt = 0;
        int n = board.size();
        int m = board[0].size();
        //left
        if(y-1 >=0 &&board[x][y-1]=='M')
            cnt++;
        //left upper
        if(y-1 >=0 && x-1 >=0 &&board[x-1][y-1] =='M')
            cnt++;
        //upper
        if(x-1>=0 && board[x-1][y] =='M')
            cnt++;
        //upper right
        if(x-1>=0 && y+1 <m && board[x-1][y+1]=='M')
            cnt++;
        //right
        if(y+1 < m && board[x][y+1]=='M')
            cnt++;
        //down right
        if(x+1 < n && y+1 < m && board[x+1][y+1]=='M')
            cnt++;
        //down
        if(x+1 < n && board[x+1][y]=='M')
            cnt++;
        //down left
        if(x+1 < n && y-1 >= 0 && board[x+1][y-1]=='M')
            cnt++;
        return cnt;
    }
    void solve(vector<vector<char>>&board,vector<int>click){
        int x = click[0];
        int y = click[1];
        //base case
        if(board[x][y]=='M'){
            board[x][y]='X';
            return ;
        }
        int n = board.size();
        int m = board[0].size();
        //Empty hai
        if(board[x][y]=='E'){
            int count = countMine(x,y,board);
            //aas paas mine ni hai toh 'B' dalo & aas paas ke check kro
            if(count == 0){
                board[x][y]='B';
                //left
                if(y-1 >=0 &&board[x][y-1]=='E')
                    solve(board,{x,y-1});
                //left upper
                if(y-1 >=0 && x-1 >=0 &&board[x-1][y-1] =='E')
                    solve(board,{x-1,y-1});
                //upper
                if(x-1>=0 && board[x-1][y] =='E')
                    solve(board,{x-1,y});
                //upper right
                if(x-1>=0 && y+1 <m &&board[x-1][y+1]=='E')
                    solve(board,{x-1,y+1});
                //right
                if(y+1 < m && board[x][y+1]=='E')
                    solve(board,{x,y+1});
                //down right
                if(x+1 < n && y+1 < m && board[x+1][y+1]=='E')
                    solve(board,{x+1,y+1});
                //down
                if(x+1 < n && board[x+1][y]=='E')
                    solve(board,{x+1,y});
                //down left
                if(x+1 < n && y-1 >= 0 && board[x+1][y-1]=='E')
                    solve(board,{x+1,y-1});
            }else{
                board[x][y]=count + '0';
            }
        }

    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        solve(board,click);
        return board;
    }
};
