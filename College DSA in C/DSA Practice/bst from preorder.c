//preorder to bst
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
void preorderTraversal();

//Create Node
TreeNode* createNode(int val){
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = val;
	root->left = root->right = NULL;
	return root;
}

//Create BST using preorder
TreeNode* constTree(int *preorder,int size,int *index,int bound){
	//base case
	if(*index >= size || bound < preorder[*index]){
		return NULL;
	}
	int element = preorder[(*index)++];
	TreeNode* root = createNode(element);
	root->left = constTree(preorder,size,index,root->val);
	root->right = constTree(preorder,size,index,bound);
	return root;
}
int main(){
	int preorder[] = {10,5,4,6,15,9,20};
	int size = sizeof(preorder)/sizeof(preorder[0]);
	int bound = INT_MAX;
	int index = 0;
	TreeNode* root = constTree(preorder,size,&index,bound);
	preorderTraversal(root);
	return 0;
}
void preorderTraversal(TreeNode* root){
	//base 
	if(!root)	return ;
	printf("%d ",root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}