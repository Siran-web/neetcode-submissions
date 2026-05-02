class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0)
            return x;

        int s = 0 , e = x/2;
        int ans = 0;

        while(s <= e){
            long long m = s + (e - s)/2;
  
            if(m * m <= x){
                ans = m;
                s = m + 1;
            }
            else
                e = m - 1;
        }

        return ans;
        
    }
};