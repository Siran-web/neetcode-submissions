class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(auto st : stones)
            pq.push(st);

        while(!pq.empty() && pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y){
                if(pq.empty())
                    pq.push(0);
                else
                    continue;    
            }
            else
                pq.push(x - y);    
        }    
        return pq.top();
    }
};
