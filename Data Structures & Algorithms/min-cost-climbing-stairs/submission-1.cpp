class Solution {
public:
    int mini(vector<int>& cost , int n , vector<int>& dp){
        if(n == 0 || n == 1)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int first = mini(cost , n -1 , dp) + cost[n-1];
        int sec = mini(cost , n -2 , dp) + cost[n-2];

        return dp[n] = min(first , sec);        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1 , -1);

        return mini(cost , n , dp);
    }
};