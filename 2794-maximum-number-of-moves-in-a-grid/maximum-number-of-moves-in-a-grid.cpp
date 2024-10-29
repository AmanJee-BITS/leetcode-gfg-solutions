class Solution {
public:
    int dfs(int row, int col, int preval, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (row >= n or row < 0 or col >= m or col < 0)
            return 0;

        int curval = grid[row][col];

        if (curval <= preval)
            return 0;
        if (dp[row][col] != 0)
            return dp[row][col];

        int d1 = dfs(row - 1, col + 1, curval, grid, dp);
        int d2 = dfs(row, col + 1, curval, grid, dp);
        int d3 = dfs(row + 1, col + 1, curval, grid, dp);

        dp[row][col] = max(d1, max(d2, d3)) + 1;

        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int max1 = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            max1 = max(max1, dfs(i, 0, -1, grid, dp) - 1);
        }

        return max1;
    }
};