class MyQueue {
public:
    int *stack1;
    int *stack2;
    int top1;
    int top2;

    MyQueue() {
        stack1=new int[10000];
        stack2=new int[10000];
        top1=top2=-1;
    }
    
    void push(int x) {
        while(top1!=-1){
            stack2[++top2]=stack1[top1--];
        }
        stack1[++top1]=x;
        while(top2!=-1){
            stack1[++top1]=stack2[top2--];
        }
    }
    int pop() {
        if(top1==-1){
            return -1;
        }
        return stack1[top1--];
    }
    
    int peek() {
        return stack1[top1];
    }
    
    bool empty() {
        return top1==-1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
