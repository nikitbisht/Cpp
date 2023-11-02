class MinStack {
public:
    stack<double>s;
    double mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                double data=val;
                s.push(2*data-mini);
                mini=val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return ;
        }
        else{
            double curr=s.top();
            s.pop();
            if(curr<mini){
                mini=2*mini-curr;
            }
        }
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }
        double curr=s.top();
        if(curr<mini){
            return mini;
        }
        return curr;
    }
    
    int getMin() {
        if(s.empty()){
            return -1;
        }
        int data=mini;
        return data;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
