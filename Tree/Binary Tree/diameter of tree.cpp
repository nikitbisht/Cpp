//Diameter of Binary Tree[Longest path between any two node]
/*
#1 Approch :- T.c:- O(N^2)
#2 Approch :- T.c:- O(N)
*/
#include<iostream>
#include<bits/stdc++.h>
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
//create tree
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
//Print tree
void inOrder(node*root){
	if(root==NULL){
		return ;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
//Return height of tree
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


//1 Approch using of height fn
int diameterOfTree(node* root){
	//base case 
	if(root==NULL){
		return 0;
	}
	int op1 = diameterOfTree(root->left);
	int op2 = diameterOfTree(root->right);
	int op3 = heightOfTree(root->left)+heightOfTree(root->right)+1;
	
	int ans=max(op1,max(op2,op3));
	return ans;
}


//2 Approch
pair<int,int> diameterFast(node* root){
	if(root==NULL){
		pair<int,int>p=make_pair(0,0);
		return p;
	}
	pair<int,int>left=diameterFast(root->left);
	pair<int,int>right=diameterFast(root->right);
	
	int op1=left.first;
	int op2=right.first;
	int op3= left.second+right.second+1;
	
	pair<int,int>ans;
	ans.first=max(op1,max(op2,op3));
	ans.second=max(left.second,right.second)+1;
	return ans;
}

int main(){
	node* root=NULL;
	root = createNode(root);
	inOrder(root);
	cout<<"\nDiameter of Tree:- "<<diameterOfTree(root)<<endl;
	cout<<"\nDiameter of Tree:- "<<diameterFast(root).first<<endl;
	return 0;	
}