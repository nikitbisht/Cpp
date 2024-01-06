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
    void calculateSum(TreeNode* root,int &ans,int temp){
        //base case
        if(!root)   return ;
        temp = temp*10 + root->val;
        if(!root->left && !root->right){
            ans += temp;
            return ;
        }
        calculateSum(root->left,ans,temp);
        calculateSum(root->right,ans,temp);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        calculateSum(root,ans,0);
        return ans;
    }
};
