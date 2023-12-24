//User function Template for C++

class node{
    public:
        int data;
        int row;
        int col;
    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node*,vector<node*>, compare> pq;
        for(int i = 0; i < K;i++){
            node* newnode = new node(arr[i][0],i,0);
            pq.push(newnode);
        }
        vector<int> ans;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            
            ans.push_back(temp->data);
            int row = temp->row;
            int col = temp->col;
            
            if(col + 1 < arr[row].size()){
                node* newnode = new node(arr[row][col+1],row,col+1);
                pq.push(newnode);
            }
        }
        return ans;
    }
};










//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
