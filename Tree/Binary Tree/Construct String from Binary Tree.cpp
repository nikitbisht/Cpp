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
    void solve(TreeNode* root,string& ans){
        if(root==NULL)  return ;
        ans.append(to_string(root->val));
        //For left subtree, if not exits but right exit so create paranthesis for null.
        if(root->left || root->right){
            ans.push_back('(');
            solve(root->left,ans);
            ans.push_back(')');
        }
        //For right subtree
        if(root->right){
            ans.push_back('(');
            solve(root->right,ans);
            ans.push_back(')');
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root,ans);
        return ans;
    }
};
