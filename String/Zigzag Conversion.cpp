class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string ans;
        int M_indx = 2*numRows;
        int T_indx = M_indx;
       for(int i = 0; i < numRows && i < s.size(); i++){
           T_indx -= 2;
           int j = i;
           bool flag = false;
           int indx = M_indx - T_indx - 2;
           while(j < s.size()){
               ans.push_back(s[j]);

               if(flag && indx > 0) j += indx;
               else  j += T_indx;

               flag = !flag;
           }
           if(T_indx == 2){
               T_indx = M_indx;
           }
       }
        return ans;
    }
};
