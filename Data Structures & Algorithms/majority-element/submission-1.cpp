class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0 , cand;

        for(auto num : nums){
            if(cnt == 0)
                cand = num;

            if(cand == num)
                cnt++;

            if(cand != num)
                cnt--;        
        }
        return cand;
    }
};