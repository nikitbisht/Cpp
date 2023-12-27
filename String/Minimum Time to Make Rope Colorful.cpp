class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int j = i+1;
        int cost = 0;
        int n = colors.size();
        while(j < n){
            if(colors[i] == colors[j]){
                if(neededTime[i] < neededTime[j]){
                    cost += neededTime[i];
                }else{
                //update array either it gives same min element for more than once.
                    cost += neededTime[j];
                    swap(neededTime[i],neededTime[j]);
                }
            }
            i++;
            j++;
        }
        return cost;
    }
};
