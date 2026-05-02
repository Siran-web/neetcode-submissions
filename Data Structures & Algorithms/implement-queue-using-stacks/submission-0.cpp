class MyQueue {
public:
    stack<int> st;
    stack<int> temp;

public:
    MyQueue() {
        
    }

    void reverse(stack<int>& st, stack<int>& temp){
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int top;

        while(!st.empty()){
            top = st.top();
            st.pop();
            if(!st.empty())
                temp.push(top);    
        }
        reverse(temp , st);
        return top;
    }
    
    int peek() {
        int top;

        while(!st.empty()){
            top = st.top();
            st.pop();
            temp.push(top);    
        }

        reverse(temp , st);
        return top;
    }
    
    bool empty() {
        return st.empty();
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