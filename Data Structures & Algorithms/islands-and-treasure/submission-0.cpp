class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int drow[4] = {0 , 1 , 0 , -1};
        int dcol[4] = {1 , 0 , -1, 0};

        queue<pair<int , int>> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            int r = top.first;
            int c = top.second;
            q.pop();

            for(int i=0 ; i<4 ; i++){

                int row = drow[i] + r;
                int col = dcol[i] + c;

                if(row >=0 && col >=0 && row < n && col < m && grid[row][col] == INT_MAX){
                    q.push({row, col});
                    grid[row][col] = grid[r][c] + 1;
                }

                else if(row >=0 && col >=0 && row < n && col < m && grid[row][col] > 0 && grid[row][col] > grid[r][c]){
                    grid[row][col] = grid[r][c] + 1;
                } 
                
            }
        }

    }
};
