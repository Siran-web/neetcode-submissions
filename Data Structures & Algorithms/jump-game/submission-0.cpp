class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int cnt = 0;

        for(int i = n-1 ; i>=0 ; i--){
            if(nums[i] == 0)
                cnt++;

            else{
                if(nums[i] <= cnt)
                    cnt++;
                else
                    cnt = 0;  
            }     
        }

        return cnt > 0 ? false : true;
    }
};
