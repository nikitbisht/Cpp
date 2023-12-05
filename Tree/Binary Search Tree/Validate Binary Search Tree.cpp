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
    bool solve(TreeNode* root, long long mini,long long maxi){
        //base case
        if(!root)   return true;

        if(root->val > mini && root->val < maxi){
            bool left = solve(root->left,mini,root->val);
            bool right= solve(root->right,root->val,maxi);
            return left && right;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
/*1 Approch :- inorder traversal of Valid binary Search tree is Shorted so we chcek its sorted or not. 
Tc:- for inorder traversal O(n) + check sorted or not O(n)= O(n)
Sc:-  O(n) stored element 

2 Approch:- As we know that left tree data < root > right tree data.
Tc:- O(n)
Sc:- O(h)   O(N) for skwee tree
*/
