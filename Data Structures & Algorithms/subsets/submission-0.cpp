class Solution {
public:
    void solve(vector<int>& nums , int index , vector<int> temp , vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        solve(nums, index+1, temp, ans);

        //not take
        temp.push_back(nums[index]);
        solve(nums, index+1 , temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);
        return ans;   
    }
};
