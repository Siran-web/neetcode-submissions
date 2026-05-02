class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int r = 0 , l = 0;
        int maxi = 0 , mini = 100;

        while(r < prices.size()){
            mini = min(mini , prices[r]);

            if(mini == prices[r])
                maxi = mini;
            else
                maxi = max(maxi , prices[r]);

            int profit = maxi - mini;
            maxProfit = max(profit , maxProfit);
            r++;
        }
        return maxProfit;
    }
};
