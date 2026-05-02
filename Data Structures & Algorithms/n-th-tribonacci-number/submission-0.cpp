class Solution {
public:
    int tri(int n , vector<int>& dp){
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;

        if(dp[n] != -1)
            return dp[n];    

        int f = tri(n-1 , dp);
        int s = tri(n-2 , dp);
        int t = tri(n-3 , dp);

        return dp[n] = f+s+t;        
    }
    int tribonacci(int n) {
        vector<int> dp(n+1 , -1);
        return tri(n, dp);
    }
};