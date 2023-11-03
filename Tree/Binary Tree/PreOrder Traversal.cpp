//PreOrder Traversal in Binary Tree
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
	node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
node* creation(node* root){
	int data;
	cout<<"Enter the node:- "<<endl;
	cin>>data;
	root=new node(data);
	if(data==-1){
		return NULL;
	}
	cout<<"Enter the data in left of "<<data<<endl;
	root->left=creation(root->left);
	cout<<"Enter the data in right of "<<data<<endl;
	root->right=creation(root->right);
	
	return root;
}
void preOrder(node*root){
	//base case
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
int main(){
	node*root;
	//creation of tree
	root=creation(root);
	
	preOrder(root);
	return 0;
}