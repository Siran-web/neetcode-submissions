class Solution {
public:
    void pre(vector<int>& nums, int index , vector<vector<int>>& ans){
        if(index == nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i = index ; i<nums.size() ; i++){
            swap(nums[index] , nums[i]);
            pre(nums , index+1 , ans);
            swap(nums[index] , nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        pre(nums, 0, ans);

        return ans;
    }
};
