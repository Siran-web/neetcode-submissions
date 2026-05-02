class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string ,vector<string>> mp;

        for(string str : strs){
            string s = str;
            sort(s.begin() , s.end());

            mp[s].push_back(str);

        }

        vector<vector<string>> ans;

        for(auto i : mp){
            vector<string> temp;
            for(auto j : i.second)
                temp.push_back(j);
            ans.push_back(temp);    
        }

        return ans;
        
    }
};
