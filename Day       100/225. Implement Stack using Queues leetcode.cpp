class MyStack {
public:
    
    queue<int>q1;
    
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int>q2;
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();    
        }
        q1=q2;
        
        
        
    }
    
    int pop() {
        int k= q1.front();
        q1.pop();
        return k;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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
