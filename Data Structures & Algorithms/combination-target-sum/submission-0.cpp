class Solution {
public:
    void solve(vector<int>& nums, int index, int target, vector<int>& temp , vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == nums.size() || target < 0)
            return;

        temp.push_back(nums[index]);
        solve(nums , index, target - nums[index] , temp , ans);

        temp.pop_back();
        solve(nums, index+1 , target , temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums , 0 , target , temp, ans);
        return ans;
    }
};
