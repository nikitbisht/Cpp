/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* temp=root;
    int pred=-1;
    int succ=-1;
    // fing the key node
    while(temp!=NULL && temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    if(!temp)   return {pred,succ};
    TreeNode* leftTree= temp->left;
    TreeNode* rightTree= temp->right;
    //Predecessor
    while(leftTree){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    //Successor
    while(rightTree){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    return {pred,succ};
}
