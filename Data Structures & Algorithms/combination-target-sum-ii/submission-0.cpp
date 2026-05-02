class Solution {
public:
    void solve(vector<int>& nums, int index , int target, vector<int>& temp , vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == nums.size() || target < 0)
            return;

        for(int i=index ; i< nums.size() ; i++){
            if(i > index && nums[i] == nums[i-1])
                continue;

            temp.push_back(nums[i]);
            solve(nums, i + 1, target - nums[i] , temp , ans);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin() , candidates.end());
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};
