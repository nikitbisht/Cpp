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
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>temp,int currSum,int targetSum){
        //base case
        if(root==NULL) return ;

        currSum+=root->val;
        temp.push_back(root->val);

         if(targetSum==currSum && root->left==NULL && root->right==NULL){
            ans.push_back(temp);
        }
        //recursive calls
        solve(root->left,ans,temp,currSum,targetSum);
        solve(root->right,ans,temp,currSum,targetSum);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,ans,temp,0,targetSum);
        return ans;
    }
};
