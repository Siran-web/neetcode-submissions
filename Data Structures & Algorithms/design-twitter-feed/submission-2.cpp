class Twitter {
public:
    unordered_map<int , priority_queue<pair<int , int>>> mp;
    unordered_map<int , set<int>> flo;
    int cnt;

public:
    Twitter() { 
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push({cnt , tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = 10;
        flo[userId].insert(userId);
        priority_queue<pair<int , int>> pq ;
        set<int> l = flo[userId];

        for(auto j: l){
            int p = 10;
            priority_queue<pair<int , int>> r = mp[j];
            while(!r.empty() && p--){
                pq.push(r.top());
                r.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty() && n--){
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flo[followerId].erase(followeeId);
    }
};
