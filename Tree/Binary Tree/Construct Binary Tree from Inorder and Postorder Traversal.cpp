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
    void createMapping(vector<int>& inorder,map<int,int>&nodes,int size){
        for(int i=0;i<size;i++){
            nodes[inorder[i]]=i;
        }
    }
    TreeNode* constructTree(vector<int>& inorder,vector<int>& postorder,map<int,int>&nodes,int &index,int size,int start,int end){
        //base case
        if(index<0||start>end){
            return NULL;
        }
        int element=postorder[index--];
        TreeNode* root = new TreeNode(element);
        int posi = nodes[element];
        root->right=constructTree(inorder,postorder,nodes,index,size,posi+1,end);
        root->left=constructTree(inorder,postorder,nodes,index,size,start,posi-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int start=0;
        int end=size-1;
        int index=size-1;
        map<int,int>nodes;
        createMapping(inorder,nodes,size);
        TreeNode* root = constructTree(inorder,postorder,nodes,index,size,start,end);
        return root;
    }
};
