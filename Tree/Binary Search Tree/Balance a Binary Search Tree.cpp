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
    void storeInorder(TreeNode* root,vector<int>&in){
        if(!root)   return ;
        storeInorder(root->left,in);
        in.push_back(root->val);
        storeInorder(root->right,in);
    }
    TreeNode* inorderToBst(vector<int>&inorder,int start,int end){
        //base case
        if(start > end) return NULL;
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = inorderToBst(inorder,start,mid-1);
        root->right = inorderToBst(inorder,mid+1,end);
        return root; 
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        //Step 1:- Store Inorder
        vector<int>inorder;
        storeInorder(root,inorder);
        //Step 2:- Made Balance BST using inorder
        int size = inorder.size();
        TreeNode* newroot = inorderToBst(inorder,0,size-1);
        return newroot;
    }
};
