class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& flood,vector<vector<int>>& image,int &iniColor,int& color,vector<int>& dRow,vector<int>& dCol){
        flood[row][col] = color;
        int n = flood.size();
        int m = flood[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == iniColor && flood[nrow][ncol] != color){
                dfs(nrow,ncol,flood,image,iniColor,color,dRow,dCol);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> flood = image;
        vector<int>dRow = {-1,0,1,0};
        vector<int>dCol = {0,1,0,-1};
        int iniColor = image[sr][sc];
        dfs(sr,sc,flood,image,iniColor,color,dRow,dCol);
        return flood;
    }
};
