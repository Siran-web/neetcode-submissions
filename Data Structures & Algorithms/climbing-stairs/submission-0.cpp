class Solution {
public:
    int steps(int n , vector<int>& dp){
        dp[2] = 2;
        dp[1] = 1;  

        if(dp[n] != -1)
            return dp[n];

        dp[n-1] = steps(n - 1 , dp) ;
        dp[n-2] = steps(n - 2 , dp) ;

        return dp[n] = dp[n-1] + dp[n-2];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return steps(n , dp);
    }
};
