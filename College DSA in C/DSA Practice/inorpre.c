//create Tree using inorder and preorder
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
void inorderTraversal();
void preorderTraversal();
void levelOrderTraversal();
//Create Node
TreeNode* createNode(int val){
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = val;
	root->left = root->right = NULL;
	return root;
}
//Find position in inorder 
int findPosi(int* inorder,int value,int start,int end){
	for(int i = start;i<=end;i++){
		if(inorder[i]==value){
			return i;
		}
	}
	return -1;
}
//Constuct Tree
TreeNode* constTree(int* inorder,int* preorder,int size,int* index,int start,int end){
	//base case
	if(*index >= size || start > end){
		return NULL;
	}
	int element = preorder[(*index)++];
	TreeNode* root = createNode(element);
	int posi = findPosi(inorder,element,start,end);
	root->left = constTree(inorder,preorder,size,index,start,posi-1);
	root->right = constTree(inorder,preorder,size,index,posi+1,end);
	return root;
}
int main(){
	int inorder[]={4,2,1,7,5,8,3,6};
	int preoder[]={1,2,4,3,5,7,8,6};
	int size = sizeof(inorder)/sizeof(inorder[0]);
	int index = 0;
	int start = 0;
	int end = size-1;
	TreeNode* root = constTree(inorder,preoder,size,&index,start,end);
	printf("Inorder of Tree \n");
	inorderTraversal(root);
	printf("\nPreorder of Tree \n");
	preorderTraversal(root);
	printf("\nLevel order Traversal:- \n");
	levelOrderTraversal(root);
	return 0;
}

void inorderTraversal(TreeNode* root){
	//base 
	if(!root)	return ;
	inorderTraversal(root->left);
	printf("%d ",root->val);
	inorderTraversal(root->right);
}
void preorderTraversal(TreeNode* root){
	//base 
	if(!root)	return ;
	printf("%d ",root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
void levelOrderTraversal(TreeNode* root){
	int front = -1;
	int rear = -1;
	TreeNode* queue[50];
	queue[++rear] = root;	//0 index
	queue[++rear] = NULL;	//1 index
	while(front!=rear){
		TreeNode* element = queue[++front];	//0th index
		if(element == NULL){
			printf("\n");
			if(front!=rear){
				queue[++rear]=NULL;
			}
		}else{
			printf("%d ",element->val);
			if(element->left){
				queue[++rear] = element->left;
			}
			if(element->right){
				queue[++rear] = element->right;
			}
		}
	}
}