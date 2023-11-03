//Binary Tree
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
//Creation of tree
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

int main(){
	node*root;
	//creation of tree
	root=creation(root);
	return 0;
}