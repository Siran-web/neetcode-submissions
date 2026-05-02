class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char ,int> mp;
        for(auto ch: s)
            mp[ch]++;

        priority_queue<pair<int , char>> maxHeap;
        for(auto ch : mp){
            if(ch.second > 0)
                maxHeap.push({ch.second , ch.first});
        } 

        string ans = "";
        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            char ch1 , ch = top.second;
            ans += ch;
            int cnt1 , cnt = top.first - 1;

            maxHeap.pop();
            if(maxHeap.empty()){
                if(cnt > 0)
                    return "";
                else
                    break;    
            }

            else{
                auto top1 = maxHeap.top();
                ch1 = top1.second;
                ans += ch1;
                cnt1 = top1.first - 1;

                maxHeap.pop();
            }    

            if(cnt > 0)
                maxHeap.push({cnt , ch});
            if(cnt1 > 0)
                maxHeap.push({cnt1 , ch1});
        }
        return ans;
    }
};