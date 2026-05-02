class Solution {
public:
    void subXor(vector<int>& nums , int index , int temp , int& ans ){
        if(index == nums.size()){
            ans += temp;
            return;
        }

        
        subXor(nums, index+1 , temp, ans);

        temp ^= nums[index];
        subXor(nums, index+1 ,temp, ans);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        subXor(nums , 0 ,temp, ans);

        return ans;
    }
};