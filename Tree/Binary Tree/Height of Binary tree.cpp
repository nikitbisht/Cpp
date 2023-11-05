//Height of Binay tree
#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int data;
		node*right;
		node* left;
	node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
node* createNode(node*root){
	int data;
	cin>>data;
	root=new node(data);
	if(data==-1){
		return NULL;
	}
	cout<<"Left of "<<data<<endl;
	root->left = createNode(root->left);
	cout<<"Right of "<<data<<endl;
	root->right = createNode(root->right);
	return root;
}

void inOrder(node*root){
	if(root==NULL){
		return ;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int heightOfTree(node* root){
	//base case
	if(root==NULL){
		return 0;
	}
	int left = heightOfTree(root->left);
	int right = heightOfTree(root->right);
	int ans = max(left,right)+1;
	return ans;
}
int main(){
	node* root=NULL;
	root = createNode(root);
	inOrder(root);
	cout<<"\nHeight of BT:- "<<heightOfTree(root)<<endl;
}