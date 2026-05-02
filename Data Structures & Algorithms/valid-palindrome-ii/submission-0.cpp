class Solution {
public:
    bool validPalindrome(string s) {
        
        int i=0 , j = s.size() - 1 , cnt = 0;

        while(i < j){
            if(s[i] != s[j]){
                cnt++;
                i--;
            }
            i++;
            j--;
        }

        if(cnt <= 1)
            return true;

        i = 0 , j = s.size() -1 , cnt = 0;
        while(i < j){
            if(s[i] != s[j]){
                cnt++;
                j++;
            }
            i++;
            j--;
        }  

        if(cnt <= 1)
            return true;

        else
            return false;      

    }
};