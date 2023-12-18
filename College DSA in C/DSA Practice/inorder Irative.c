#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int data){
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val=data;
	root->left = root->right = NULL;
	return root;
}

TreeNode* createBst(TreeNode* root,int data){
	if(!root)
		return createNode(data);
	if(root->val>data){
		root->left = createBst(root->left,data);
	}else{
		root->right = createBst(root->right,data);
	}
	return root;
}

TreeNode* takeInput(TreeNode* root){
	int data;
	printf("\nEnter the data:- ");
	scanf("%d",&data);
	while(data!=-1){
		root = createBst(root,data);
		scanf("%d",&data);
	}
	return root;
}
/*
void inorder(TreeNode* root){
	if(!root)	return ;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}
*/
void inorder(TreeNode* root){
	//moris traversal
	TreeNode* curr = root;
	while(curr){
		if(!curr->left){
			printf(" %d",curr->val);
			curr
			=curr->right;
		}else{
			TreeNode* pred = curr->left;
			while(pred->right && pred->right != curr){
				pred= pred->right;
			}
			if(pred->right==NULL){
				pred->right = curr;
				curr = curr->left;
			}else{
				pred->right = NULL;
				printf(" %d",curr->val);
				curr = curr->right;
			}
		}
	}
}
int main(){
	TreeNode* root;
	root = takeInput(root);
	printf("\nInorder:- \n");
	inorder(root);
	return 0;
}
