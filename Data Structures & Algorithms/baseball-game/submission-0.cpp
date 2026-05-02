class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for(auto x : operations){

            if(x == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            }

            else if(x == "C"){
                st.pop();
            }
            else if(x == "D"){
                int top = st.top();
                st.push(top * 2);
            }
            else
                st.push(stoi(x));
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};