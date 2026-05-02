class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // vector<int> tmp(n);
        // for (int i = 0; i < n; i++) {
        //     tmp[(i + k) % n] = nums[i];
        // }
        // for (int i = 0; i < n; i++) {
        //     nums[i] = tmp[i];
        // }

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
    }
};