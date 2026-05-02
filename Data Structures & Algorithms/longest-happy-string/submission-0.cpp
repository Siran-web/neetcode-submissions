class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int , char>> maxHeap;

        if(a > 0) maxHeap.push({a , 'a'});
        if(b > 0) maxHeap.push({b , 'b'});
        if(c > 0) maxHeap.push({c , 'c'});

        while(!maxHeap.empty()){
            auto [cnt , ch] = maxHeap.top();
            maxHeap.pop();
            int s = ans.size();

            if(s > 1 && ans[s-1] == ch && ans[s-2] == ch){
                if(maxHeap.empty())
                    break;
                    
                auto[cnt2 , ch2] = maxHeap.top();
                cnt2--;
                maxHeap.pop();
                ans += ch2;

                if(cnt2 > 0)
                    maxHeap.push({cnt2 , ch2});

                maxHeap.push({cnt , ch});
            }

            else{
                cnt--;
                ans += ch;
                if(cnt > 0)
                    maxHeap.push({cnt-- , ch});   
            }
            
        }
        return ans;
    }
};