/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class info{
     public:
        int maxi;
        int mini;
        int sum;
        bool isbst;

        info(){

        }
        info(int maxi,int mini,int sum,bool isbst){
            this->maxi = maxi;
            this->mini = mini;
            this->sum = sum;
            this->isbst = isbst;
        }
 };
class Solution {
private:
    info solve(TreeNode* root,int& maxsum){
        //base case
        if(!root)
        return info(INT_MIN,INT_MAX,0,true);

        info left = solve(root->left,maxsum);
        info right = solve(root->right,maxsum);

        info ans;
        ans.mini = min(root->val,left.maxi);
        ans.maxi = max(root->val,right.mini);

        if((left.isbst && right.isbst)&&(root->val>left.maxi) && (root->val<right.mini)){
            ans.isbst=true;
            ans.sum = left.sum + right.sum + root->val;
            maxsum=max(ans.sum,maxsum);
        }
        return ans;
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        info temp = solve(root,maxsum);
        return maxsum;
    }
};
