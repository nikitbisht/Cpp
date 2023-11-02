#include <bits/stdc++.h> 
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    int freespot;
    NStack(int N, int S)
    {
        arr=new int[S];
        top=new int[N];
        next=new int[S];
        freespot=0;
        //Setup top of stack
        for(int i=0;i<N;i++){
            top[i]=-1;
        }
        //Setup freeSpace index
        for(int i=0;i<S;i++){
            next[i]=i+1;
        }
        //Last index
        next[S-1]=-1;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot==-1){
            return false;
        }
        //find index;
        int index=freespot;
        
        //update freespot;
        freespot=next[index];
        
        //set value
        arr[index]=x;

        //Update next
        next[index]=top[m-1];

        //update top
        top[m-1]=index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;

        freespot=index;

        return arr[index];
    }
};
