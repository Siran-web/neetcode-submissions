class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int s = 0 , e = matrix.size() - 1;
        int col = e;

        while(s <= e){
            int m = s + (e - s)/2;

            if(matrix[m][0] <= target){
                col = m;
                s = m + 1;
            }
            else
                e = m - 1;
        }

        s = 0 , e = matrix[0].size();

        while(s <= e){
            int m = s + (e - s)/2;

            if(matrix[col][m] == target)
                return true;
            else if(matrix[col][m] < target)
                s = m + 1;
            else
                e = m - 1;        
        }

        return false;
        
    }
};
