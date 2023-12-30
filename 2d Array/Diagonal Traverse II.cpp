//TLE Solution
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        int row = 0;
        int col = 0;
        //Upper Diagonal
        for(int i = 0; i < nums.size(); i++){
            row = i;
            col = 0;
            while(row != -1){
                if(col < nums[row].size()){
                    ans.push_back(nums[row][col]);
                }
                row--;
                col++;
            }
        }
        //Finding maxCol 
        int maxCol = 0;
        for(int i = 0; i < nums.size(); i++)
            maxCol = max(maxCol,int(nums[i].size()));

        //Lower Diagonal
        int i = nums.size() -1;
        for(int j = 1; j < maxCol; j++){
            col = j;
            row = i;
            while(row != -1){
                if(col < nums[row].size()){
                    ans.push_back(nums[row][col]);
                }
                row--;
                col++;
            }
        }
        return ans;
    }
};
