#include<iostream>
using namespace std;
class TreeNode{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
	
	TreeNode(int data){
		this->left=this->right=NULL;
		this->data=data;
	}
};
void createTree(TreeNode* &root,int data){
	//base case
	if(root==NULL){
		root =  new TreeNode(data);
		return ;
	}
	if(root->data>data){
		createTree(root->left,data);
	}else{
		createTree(root->right,data);
	}
}
void takeInput(TreeNode* &root){
	cout<<"-1 to stop input "<<endl<<endl;
	cout<<"Enter the data:- ";
	int data;
	cin>>data;
	while(data!=-1){
		createTree(root,data);
		cin>>data;
	}
}

TreeNode* getMini(TreeNode* root){
	TreeNode* temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

TreeNode* deleteFromBst(TreeNode*& root,int k){
	if(!root)	return NULL;
	if(root->data==k){
	//0 child
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}
	//1 child
		if(root->left && !root->right){
			TreeNode* temp= root->left;
			delete root;
			return temp;
		}
		if(!root->left && root->right){
			TreeNode* temp= root->right;
			delete root;
			return temp;
		}
	//2 child
		if(root->left && root->right){
			int mini = getMini(root->right)->data;
			root->data=mini;
			root->right=deleteFromBst(root->right,mini);
		}
	}
	if(root->data>k)
		root->left=deleteFromBst(root->left,k);
	else	
		root->right=deleteFromBst(root->left,k);
	return root;
}
void inorderTraversal(TreeNode* root){
	if(!root)	return ;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}
int main(){
	int k;
	TreeNode* root=NULL;
	takeInput(root);
	cout<<"Inorder Traversal"<<endl;
	inorderTraversal(root);
	cout<<"\nEnter the element to delete from bst:- ";
	cin>>k;
	root=deleteFromBst(root,k);
	cout<<"After deletion Inorder Traversal"<<endl;
	inorderTraversal(root);
	return 0;
}
