class Solution {
public:
    int steal(vector<int>& nums, int n , vector<int>& dp){
        if(n < 0)
            return -1;
        if(n == 0)
            return nums[0]; 
        if(n == 1)
            return max(nums[0] , nums[1]);     

        if(dp[n] != -1)
            return dp[n];

        int f = steal(nums , n - 1 , dp);
        int s = steal(nums , n - 2 , dp) + nums[n];

        return dp[n] = max(f , s);        
    }
    int rob(vector<int>& nums) {
        int n = nums.size() -1;
        vector<int> dp(n+1 , -1);

        return steal(nums , n , dp);
    }
};
