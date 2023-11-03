/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void inOrder(BinaryTreeNode<int> *root,int &k){
    if(root==NULL){
        return ;
    }
    inOrder(root->left, k);
    if(root->left==NULL&&root->right==NULL){
        k++;
    }
    inOrder(root->right,k);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int k=0;
    inOrder(root,k);
    return k;
}
