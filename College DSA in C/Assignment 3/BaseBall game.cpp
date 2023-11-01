
class Solution {
    private:
    int top=-1;
    int stack[1000];
    void push(int data){
        if(top==999){
            cout<<"stack overflow"<<endl;
        }
        else{
            stack[++top]=data;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            return stack[top--];
        }
    }
    inline int peek1(){
        return stack[top];
    }
    inline int peek2(){
        return stack[top-1];
    }
public:
    int calPoints(vector<string>& operations) {
        int i=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                pop();
            }
            else if(operations[i]=="D"){
                push(peek1()*2);
            }
            else if(operations[i]=="+"){
                push(peek2()+peek1());
            }
            else{
                 push(stoi(operations[i]));
            }
        }
        int data=0;
        while(top!=-1){
            data+=pop();
        }
        return data;
    }
};
