class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int s = 1 , e = INT_MIN;

        for(auto i: piles)
            e = max(e , i);

        int ans = 0;
        while(s <= e){
            int m = s + (e - s)/2;

            int cnt = 0;
            for(auto i: piles)
                cnt += (i + m - 1)/m;

            if(cnt <= h){
                ans = m;
                e = m - 1;
            }    
            else
                s = m + 1;
            
        }    
        return ans;
    }
};
