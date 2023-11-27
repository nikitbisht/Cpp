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
class Solution {
private:
    void solve(TreeNode* root,vector<int>ans,int targetSum,int & count){
        //base case
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        //left path call
        solve(root->left,ans,targetSum,count);
        //right path call
        solve(root->right,ans,targetSum,count);

        int size=ans.size();
        double sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=ans[i];
            if(sum==targetSum){
                count++;
            }
        }
        ans.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root==NULL){
            return 0;
        }
        vector<int>ans;
        int count=0;
        solve(root,ans,targetSum,count);
        return count;
    }
};
