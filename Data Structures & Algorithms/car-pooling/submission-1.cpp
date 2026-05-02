class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;

        for(auto t : trips){
            int cap = t[0];
            int s = t[1];
            int e = t[2];

            pq.push({s , cap});
            pq.push({e , -cap});
        }

        int c = 0;
        while(!pq.empty()){

            int cap = pq.top().second;
            pq.pop();

            c += cap;
            if(c > capacity)
                return false;
        }
        return true;
    }
};