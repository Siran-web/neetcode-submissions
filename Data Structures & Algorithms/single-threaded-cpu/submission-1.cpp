class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> rs;

        vector<int> ans;
    
        for(int i=0 ; i<tasks.size() ; i++){
            int s = tasks[i][0];
            int time = tasks[i][1];

            pq.push({s , {time , i}});

        }

        int currTime = 0;

        while(!pq.empty() || !rs.empty()){

            if(rs.empty()){
                int s = pq.top().first;
                currTime = max(currTime , s);
            }

            while(!pq.empty() && currTime >= pq.top().first){
                int s = pq.top().first;
                int time = pq.top().second.first;
                int i = pq.top().second.second;
                
                rs.push({time , {i , s}});
                pq.pop();
            }

            int t1 = rs.top().first;
            int i1 = rs.top().second.first;
            rs.pop();

            currTime += t1;
            ans.push_back(i1);
            
            
        }
        return ans;
    }
};