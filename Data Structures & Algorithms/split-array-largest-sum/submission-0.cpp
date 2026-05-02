class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int s = 0 , e = 0;

        for(auto num: nums){
            s = max(num , s);
            e += num;
        }

        int ans = s;

        while(s <= e){
            int m = s + (e - s)/2;

            int cnt = 0 , sum = 0;
            for(int i=0 ; i<nums.size() ; i++){
                sum += nums[i];

                if(sum == m){
                    sum = 0;
                    cnt++;
                }
                else if(sum > m){
                    sum = nums[i];
                    cnt++;
                }
            }

            if(sum >0)
                cnt++;

            if(cnt <= k){
                ans = m;
                e = m - 1;
            }
            else
                s = m + 1;

        }
        return ans;
    }
};