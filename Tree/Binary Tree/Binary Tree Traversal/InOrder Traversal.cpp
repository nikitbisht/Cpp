class Solution {
private:
    void leftTraversal(Node* root,vector<int>&ans){
        //base case
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        ans.push_back(root->data);
        if(root->left){
            leftTraversal(root->left,ans);
        }else{
            leftTraversal(root->right,ans);
        }
    }
    
    void leafTraversal(Node* root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
    }
    
    void rightTraversal(Node* root,vector<int>&ans){
        if((root==NULL) || root->left==NULL && root->right==NULL){
            return ;
        }
        if(root->right){
            rightTraversal(root->right,ans);
        }
        else{
            rightTraversal(root->left,ans);
        }
        //we write it hear because we need our right path in reverse way
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left part
        leftTraversal(root->left,ans);
        //leaf Traversal
            //left subtree
        leafTraversal(root->left,ans);
            //right subtree
        leafTraversal(root->right,ans);
        //right part
        rightTraversal(root->right,ans);
        
        return ans;
    }
};