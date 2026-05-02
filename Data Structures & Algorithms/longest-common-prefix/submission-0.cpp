class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)
            return ans;

        int n = strs[0].size();

        for(int i=0 ; i<strs.size() ; i++)
            n = min(n , (int)strs[i].size());

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<strs.size() ; j++){
                if(strs[0][i] != strs[j][i])
                    return ans;
            }
            ans += strs[0][i];
        }    
        return ans;
    }
};