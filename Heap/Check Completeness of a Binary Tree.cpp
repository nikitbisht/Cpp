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
    int count(TreeNode* root){
        if(!root)   return 0;
        int left = count(root->left);
        int right = count(root->right);
        int ans = left + right + 1;
        return ans;
    }
    bool isCBT(TreeNode* root,int index, int countNode){
        if(!root)   return true;
        if(index > countNode) return false;
        bool left = isCBT(root->left , 2*index , countNode);
        bool right = isCBT(root->right , 2*index+1 ,countNode);
        
        return left && right;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        //1 order indexing
        int index = 1;
        int countNode = count(root);
        return isCBT(root,index,countNode);
    }
};
