class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0 , e = nums.size() - 1;

        if(nums.size() == 1 && nums[0] == target)
            return true;

        if(nums[s] == nums[e]){
            s++;
            e--;
        }

        while(s <= e){
            int m = s + (e - s)/2;

            if(nums[m] == target)
                return true;

            else if(nums[s] <= nums[m]){
                if(nums[s] <= target && nums[m] > target)
                    e = m - 1;
                else
                    s = m + 1;    
            }
            else{
                if(nums[e] >= target && nums[m] < target)
                    s = m + 1;
                else    
                    e = m - 1;
            }    
        }
        return false;
    }
};