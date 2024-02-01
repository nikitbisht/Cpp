#include<unordered_map>
class Solution {
public:
    bool isHappy(int n) {
        int sum = n;
        unordered_map<int,bool>M;
        while (1){
            if(sum == 1)return true;
            cout<<sum<<endl;
            if(M.find(sum) != M.end()) return false;
            M[sum]=true;
            int temp = sum;
            sum = 0;
            while (temp){
                int rem = temp % 10;
                sum += rem*rem;
                temp = temp/10;
            }
        }
    }
};
