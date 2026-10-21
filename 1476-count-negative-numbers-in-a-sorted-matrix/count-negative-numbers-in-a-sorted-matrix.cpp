class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(grid[i][m - 1] > 0) continue;
            else if(grid[i][0] < 0) count += m;
            else {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] < 0) count++;
                }
            } 
        }

        return count;
    }
};