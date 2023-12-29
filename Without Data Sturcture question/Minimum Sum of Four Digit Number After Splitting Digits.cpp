class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        //Store digit into the array
        while(num){
            int d = num % 10;
            arr.push_back(d);
            num = num / 10;
        }
        sort(arr.begin(),arr.end());
        int ans = ((arr[0]*10)+arr[3]) + ((arr[1]*10)+arr[2]);
        return ans;
    }
};
