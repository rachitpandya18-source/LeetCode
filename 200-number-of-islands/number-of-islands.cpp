class Solution {
private:
    void bfsTraversal(vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m, int rStart, int cStart) {
        queue<pair<int, int>> q;
        q.push({rStart, cStart});
        vis[rStart][cStart] = 1;

        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            if(currRow - 1 >= 0 && !vis[currRow - 1][currCol] && grid[currRow - 1][currCol] == '1') {
                q.push({currRow - 1, currCol});
                vis[currRow - 1][currCol] = 1;
            }
            if(currCol + 1 < m && !vis[currRow][currCol + 1] && grid[currRow][currCol + 1] == '1') {
                q.push({currRow, currCol + 1});
                vis[currRow][currCol + 1] = 1;
            }
            if(currRow + 1 < n && !vis[currRow + 1][currCol] && grid[currRow + 1][currCol] == '1') {
                q.push({currRow + 1, currCol});
                vis[currRow + 1][currCol] = 1;
            }
            if(currCol - 1 >= 0 && !vis[currRow][currCol - 1] && grid[currRow][currCol - 1] == '1') {
                q.push({currRow, currCol - 1});
                vis[currRow][currCol - 1] = 1;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    bfsTraversal(grid, vis, n, m, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};