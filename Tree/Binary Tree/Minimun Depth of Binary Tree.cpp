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
    int solve(TreeNode*root){
        //base case
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        int left=solve(root->left);
        int right =solve(root->right);
        
        int ans=min(left,right)+1;
        return ans;
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return solve(root);
        
    }
};
