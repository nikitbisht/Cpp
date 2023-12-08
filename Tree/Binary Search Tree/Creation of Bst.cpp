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

void inorderTraversal(TreeNode* root){
	if(!root)	return ;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}
int main(){
	TreeNode* root=NULL;
	takeInput(root);
	cout<<"Inorder Traversal"<<endl;
	inorderTraversal(root);
}
