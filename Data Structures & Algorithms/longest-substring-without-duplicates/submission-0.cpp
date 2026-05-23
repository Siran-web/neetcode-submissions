class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0 , right = 0 , maxi = 0;

        while(right < s.size()){
            mp[s[right]]++;

            while(mp[s[right]] > 1 && left < right){
                mp[s[left]]--;
                left++;
            }

            maxi = max(maxi , right - left + 1);
            right++;
        }
        return maxi;
    }
};
