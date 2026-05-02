class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int profit = 0;
        int maxi = prices[n] ;

        for(int i = n ; i>=0 ; i--){
            maxi = max(prices[i] , maxi);

            if(maxi > prices[i]){
                profit += maxi - prices[i];
                maxi = prices[i];
            }
            
        }
        return profit;
    }
};