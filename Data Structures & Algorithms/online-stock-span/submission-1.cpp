class StockSpanner {
public:
    stack<int> st;
    stack<int> temp;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;

        while(!st.empty() && st.top() <= price){
            int top = st.top();
            st.pop();
            cnt++;
            temp.push(top);
        }
        while(!temp.empty()){
            int top = temp.top();
            temp.pop();
            st.push(top);
        }
        st.push(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */