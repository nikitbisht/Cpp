//Bulid From Level order
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
void bulidformLevelOrder(node* &root){
	queue<node*>q;
	cout<<"Enter root data:- "<<endl;
	int data;
	cin>>data;
	root=new node(data);
	q.push(root);
	while(!q.empty()){
		node*temp=q.front();
		q.pop();
		int left;
		cout<<"Enter data in left of "<<temp->data<<endl;
		cin>>left;
		if(left!=-1){
			temp->left= new node(left);
			q.push(temp->left);
		}
		int right;
		
		cout<<"Enter data in right of "<<temp->data<<endl;
		cin>>right;
		if(right!=-1){
			temp->right=new node(right);
			q.push(temp->right);
		}
	}
}
void inOrder(node* root){
	if(root==NULL){
		return ;
	}
	
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int main(){
	node* root;
	bulidformLevelOrder(root);
	cout<<"InOrder Traversal"<<endl;
	inOrder(root);
	return 0;
}