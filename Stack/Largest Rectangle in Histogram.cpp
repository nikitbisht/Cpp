class Solution {
private:
    vector<int> nextMiniIndex(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>preMiniIndex(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next=nextMiniIndex(heights);
        vector<int>pre=preMiniIndex(heights);
        int area=INT_MIN;
        int n=heights.size();
        for(int i=0; i<n; i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b = next[i]-pre[i]-1;
            int newarea = l*b;
            area=max(area,newarea);
        }
        return area;
    }
};
