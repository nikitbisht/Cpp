// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
            //Hd,value/data
        map<int,int>topNode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            int Hd=temp.second;
            Node* frontNode=temp.first;
            //means at hd key there is not value 
            if(topNode.find(Hd)==topNode.end()){
                topNode[Hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,Hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,Hd+1));
            }
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        return ans;
    }

};
