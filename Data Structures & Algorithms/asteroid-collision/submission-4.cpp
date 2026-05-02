class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(auto ast : asteroids){
            if(st.empty()){
                st.push(ast);
                continue;
            }

            bool collide = false;

            while(!st.empty() && st.top() > 0 && ast < 0){

                int top = st.top();

                if(top == -ast){
                    collide = true;
                    st.pop();
                    break;
                }

                else if(top < -ast){
                    st.pop();
                }

                else{
                    collide = true;
                    break;
                }
            }
            if(collide == false)
                st.push(ast);
              
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};