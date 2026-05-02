class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0 , e = 0;

        for(auto i: weights){
            e += i;
            s = max(i , s);
        }

        int ans = e;

        while(s <= e){
            int m = s + (e - s)/2;

            int sum = 0 , cnt = 0;
            for(int i=0 ; i<weights.size() ; i++){
                sum += weights[i];

                if(sum == m){
                    sum = 0;
                    cnt++;
                }
                else if(sum > m){
                    sum = weights[i];
                    cnt++;
                }
            }

            if(sum > 0)
                cnt++;

            if(cnt <= days){
                ans = m;
                e = m - 1;
            }    
            else
                s = m + 1;
        }    
        return ans;
    }
};