class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> q2;
        int res;
        while(!q1.empty())
        {
            if(q1.size()>1)
                q2.push(q1.front());
            res=q1.front();
            q1.pop();
        }
        q1=q2;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> q2;
        int res;
        while(!q1.empty())
        {
            q2.push(q1.front());
            res=q1.front();
            q1.pop();
        }
        q1=q2;
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size()>0?false:true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */