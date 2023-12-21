// User function Template for C++

class Solution{
    private:
        void heapify(vector<int>& ans,int indx,int size){
            int left = 2*indx+1;
            int right = 2*indx+2;
            int temp = indx;
            if(left < size && ans[left] > ans[temp]){
                temp = left;
            }
            if(right < size && ans[right] > ans[temp]){
                temp = right;
            }
            if(temp != indx){
                swap(ans[indx],ans[temp]);
                heapify(ans,temp,size);
            }
        }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans;
        ans.insert(ans.end(),a.begin(),a.end());
        ans.insert(ans.end(),b.begin(),b.end());
        int size = m+n;
        for(int i = size/2-1;i>=0;i--){
            heapify(ans,i,size);
        }
        return ans;
    }
};
