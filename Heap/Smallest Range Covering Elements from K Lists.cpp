class node{
    public:
        int data;
        int row;
        int col;
    //Constructor
    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<node* , vector<node*>,compare> minheap;
        
        //Create heap
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i < k; i++){
            minheap.push(new node(nums[i][0],i,0));
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
        }

        int start = mini;
        int end = maxi;

        //Process
        while(!minheap.empty()){
            node* temp = minheap.top();
            minheap.pop();

            //update mini
            mini = temp->data;

            //update range;
            if((maxi - mini) < (end - start)){
                end = maxi;
                start = mini;
            }

            int row = temp->row;
            int col = temp->col;
            
            //update maxi
            if(col+1 < nums[row].size()){
                minheap.push(new node(nums[row][col+1],row,col+1));
                maxi = max(maxi , nums[row][col+1]);
            }else{
                break;
            }
        }

        return {start,end};
    }
};
