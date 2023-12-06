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
    TreeNode* getMini(TreeNode* root){
        //base case
        if(!root) return NULL;
        if(!root->left) return root;
        return getMini(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case 
        if(!root)   return NULL;

        if(root->val==key){
            //0 child
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //1 child
                //left exist
                if(root->left && !root->right){
                    TreeNode* temp = root;
                    root = root->left;
                    delete temp;
                    return root;
                }
                //right exist
                if(!root->left && root->right){
                    TreeNode* temp= root;
                    root=root->right;
                    delete temp;
                    return root;
                }
            //2 child
            if(root->left && root->right){
                int mini = getMini(root->right)->val;
                root->val=mini;
                root->right= deleteNode(root->right,mini); 
            }
        }
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        else
            root->right = deleteNode(root->right,key);
        return root;
    }
};
