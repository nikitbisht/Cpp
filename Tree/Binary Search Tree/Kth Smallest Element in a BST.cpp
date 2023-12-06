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
    int solve(TreeNode*root,int k,int &i){
        //base case
        if(!root)
            return -1;
        int left =  solve(root->left,k,i);
        if(left!=-1)
            return left;
        i++;
        if(i==k)
             return root->val;
        else
            return solve(root->right,k,i);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root,k,i);
    }
};
/*
#1 Approch:- store inorder traversal of bst in array/vector and then return k-1th index of array
Tc:- O(n)
Sc:- O(n)

#2 Approch:- through recuresion and use variable for checking kth element
Tc:- O(n)
Sc:- O(h)   for skwee tree O(N)
*/
