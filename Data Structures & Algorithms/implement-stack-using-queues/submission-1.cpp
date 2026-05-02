class MyStack {
public:
    queue<int> q;
    queue<int> temp;
public:
    MyStack() {
    }

    void reverse(queue<int>& q , queue<int>& temp){
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int top;
        while(!q.empty()){
            top = q.front();
            q.pop();
            if(!q.empty())
                temp.push(top);
        } 
        reverse(temp , q);
        return top; 
    }
    
    int top() {
        int top;
        while(!q.empty()){
            top = q.front();
            temp.push(top);
            q.pop();
        } 
        reverse(temp , q);
        return top; 
    }
    
    bool empty() {
        return q.empty();
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