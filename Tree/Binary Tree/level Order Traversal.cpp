//Level Order Traversal in Binary Tree
#include<iostream>
#include<queue>
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
void levelOrderedTraversal(node*root){
	queue<node*>q;
	q.push(root);
	
	q.push(NULL);	//Seprator
	
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if(temp==NULL){
			//previous level is complete
			cout<<endl;
			if(!q.empty()){
				//queue still have some chile node
				q.push(NULL);
			}
		}else{
			cout<<temp->data<<" ";
			
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
int main(){
	node*root;
	//creation of tree
	root=creation(root);
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	levelOrderedTraversal(root);
	return 0;
}