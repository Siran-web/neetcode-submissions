class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int , int> com;

        for(int i=0 ; i<n ; i++)
            com[target - nums[i]] = i ;

        for(int i=0 ; i<n ; i++){
            if(com.find(nums[i]) != com.end() && i != com[nums[i]] )
                return {i , com[nums[i]]};
        }
        return {};
    }
};
