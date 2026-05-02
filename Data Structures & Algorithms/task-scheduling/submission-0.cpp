class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> vec(26 , 0);
        for(auto task : tasks)
            vec[task-'A']++;

        priority_queue<int> maxHeap;
        for(auto cnt : vec){
            if(cnt > 0)
                maxHeap.push(cnt);
        }    

        int time = 0;
        queue<pair<int , int>> pq;

        while(!pq.empty() || !maxHeap.empty()){
            time++;

            if(maxHeap.empty())
                time = pq.front().second;

            else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                if(cnt > 0)
                    pq.push({cnt , time + n});    
            } 

            if(!pq.empty() && pq.front().second == time){
                maxHeap.push(pq.front().first);
                pq.pop();
            } 
            
        }
        return time;
    }
};
