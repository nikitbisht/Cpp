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
    void createMapping(vector<int>&in, int size, map<int,int>& nodes){
        for(int i=0;i<size;i++){
            nodes[in[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,map<int,int>&nodes,int 
    &index,int size,int start,int end){
        //base case
        if(index>=size||start>end){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root=new TreeNode(element);

        int posi = nodes[element];

        root->left=solve(preorder,inorder,nodes,index,size,start,posi-1);
        root->right=solve(preorder,inorder,nodes,index,size,posi+1,end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int size=preorder.size();
        int start=0;
        int end=size-1;
        map<int,int>nodes;
        //create mapping with their position
        createMapping(inorder,size,nodes);

        TreeNode* ans = solve(preorder,inorder,nodes,index,size,start,end);
        return ans;
    }
};
