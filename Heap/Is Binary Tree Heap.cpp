// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private:
    int countNode(struct Node*tree){
        if(!tree) return 0;
        int left = countNode(tree->left);
        int right = countNode(tree->right);
        int ans = left + right + 1;
        return ans;
    }
    
    bool solve(struct Node* tree,int indx,int size){
        if(!tree)   return true;
        if(indx >= size)    return false;
        
        bool left = solve(tree->left, 2*indx+1 ,size);
        bool right = solve(tree->right,2*indx+2,size);
        return left && right;
    }
    bool maxOrder(struct Node* root){
        if(!root->left && !root->right) return true;
        if(!root->right) return root->data > root->left->data;                     
        
        bool left = maxOrder(root->left);
        bool right = maxOrder(root->right);
        
        bool ans = left && right;
        
        ans = ans && root->data > root->left->data && root->data > root->right->data;                 
        return ans;
    }
  public:
    bool isHeap(struct Node* tree) {
        bool isCbt = solve(tree,0,countNode(tree));
        if(!isCbt)
            return false;
        return maxOrder(tree);
    }
};
