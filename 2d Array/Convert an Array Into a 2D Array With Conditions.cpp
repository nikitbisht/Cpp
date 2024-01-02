class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>rows;
        //Create map to store frequency
        unordered_map<int ,int > freqMap;
        int maxRow = 0;

        //update frequency 
        for(auto i : nums){
            freqMap[i]++;
            maxRow = max(maxRow,freqMap[i]);
        }

        for(int j = 0; j < maxRow; j++){
            for( auto& i : freqMap){
                if(i.second >= 1){
                    rows.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(rows);
            rows.erase(rows.begin(), rows.end());
        }
        return ans;
    }
};
