class Solution {
public:
    void solve(int index, string digits, string& temp, unordered_map<int, list<char>>& comb, vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(auto i: comb[digits[index] - '0']){
            temp.push_back(i);
            solve(index + 1, digits, temp, comb, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
            
        unordered_map<int, list<char>> comb;
        comb[2] = {'a','b','c'};
        comb[3] = {'d','e','f'};
        comb[4] = {'g','h','i'};
        comb[5] = {'j','k','l'};
        comb[6] = {'m','n','o'};
        comb[7] = {'p','q','r','s'};
        comb[8] = {'t','u','v'};
        comb[9] = {'w','x','y','z'};
       
        string temp;

        solve(0 , digits, temp, comb, ans);
        return ans;
    }
};
