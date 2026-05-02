class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0 , j = 0 , k = nums.size() - 1;

        while(i <= k && j <= i){
            if(nums[i] == 0){
                swap(nums[i] , nums[j]);
                j++;
                i++;
            }

            else if(nums[i] == 2){
                swap(nums[i] , nums[k]);
                k--;
            }
            else
                i++;
        }

        // for(int i=0 ; i<nums.size() ; i++){
        //     if(zero > 0){
        //         nums[i] = 0;
        //         zero--;
        //     }
        //     else if(one > 0){
        //         nums[i] = 1;
        //         one--;
        //     }
        //     else
        //         nums[i] = 2;
        // }
    }
};