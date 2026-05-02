class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;

        for(auto p : points){
            int dis = pow(p[0] , 2) + pow(p[1] , 2);

            pq.push({dis , {p[0] , p[1]}});
        }

        vector<vector<int>> ans;

        while(k--){
            auto top = pq.top();
            pq.pop();
            vector<int> temp;

            temp = {top.second.first , top.second.second};
            ans.push_back(temp);
        }

        return ans;
    }
};
