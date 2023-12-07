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
    void inorderStored(TreeNode* root,vector<int>& inorder){
        //base case
        if(!root)   return ;
        inorderStored(root->left,inorder);
        inorder.push_back(root->val);
        inorderStored(root->right,inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderStored(root,inorder);
        int i=0,j=inorder.size()-1;
        int sum=0;
        while(i<j){
            sum=inorder[i]+inorder[j];
            if(sum==k)  return true;
            else if(sum>k)   j--;
            else if(sum<k)  i++;
        }
        return false;
    }
};
