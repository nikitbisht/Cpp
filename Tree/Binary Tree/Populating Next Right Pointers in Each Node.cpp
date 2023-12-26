/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //base case 
        if(!root){
            return NULL;
        }
        
        if(root->left){
            root->left->next = root->right;
        }
        if(root->next && root->right)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};


//Amother method using queue


class Solution {
public:
    Node* connect(Node* root) {
        //base case 
        if(!root){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                Node* temp = q.front();
                q.pop();
                if(size > 1){
                    temp->next = q.front();
                }
                if(temp->left){
                    q.push(temp->left);
                    q.push(temp->right);
                }
                size--;
            }
        }
        return root;
    }
};
