class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>temp =  temperatures;
        int n = temp.size();
        vector<int> ans(n , 0);

        stack<pair<int, int>> st;

        for(int i=0 ; i<n ; i++){

            while(!st.empty() && st.top().first < temp[i]){
                int top = st.top().first;
                int index = st.top().second;

                st.pop();
                ans[index] = i-index;
            }

            st.push({temp[i] , i});
        }
        return ans;
    }
};
