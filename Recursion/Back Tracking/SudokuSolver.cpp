class Solution {
private:
    bool isSafe(int row,int col,char ch,vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            //row
            if(board[row][i]==ch)
                return false;
            //column
            if(board[i][col]==ch)
                return false;
            //3*3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                //empty or not
                if(board[row][col]=='.'){
                    //check for which is safe
                    for(int val=1; val<=9; val++){
                        char ch = val+'0';
                        if(isSafe(row,col,ch,board)){
                            board[row][col]=ch;
                            bool aageSolPossi = solve(board);
                            if(aageSolPossi) return true;
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    //koi bi value ke liye safe ni hai
                    return false;
                }
            }
        }
        //all places are fill
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
