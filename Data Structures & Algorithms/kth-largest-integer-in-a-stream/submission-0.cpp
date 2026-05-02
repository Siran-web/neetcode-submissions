class KthLargest {
public:
    priority_queue<int> pq;
    stack<int> st;
    int pos;

public:
    KthLargest(int k, vector<int>& nums) {
        for(auto num : nums)
            pq.push(num);

        pos = k;
    }
    
    int add(int val) {
        pq.push(val);
        int n = pos-1;

        while(n--){
            st.push(pq.top());
            pq.pop();
        }
        int top = pq.top();

        while(!st.empty()){
            pq.push(st.top());
            st.pop();
        }
        return top;
    }
};
