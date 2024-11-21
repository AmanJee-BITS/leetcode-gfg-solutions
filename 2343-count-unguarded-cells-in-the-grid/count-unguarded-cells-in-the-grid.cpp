class Solution {
public:
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& count,
             int dir) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (grid[i][j] == 2 || grid[i][j] == 1) {
            return;
        }

        if (grid[i][j] == 0) {
            grid[i][j] = -1;
            count--;
        }

        if (dir == 1)
            dfs(grid, m, n, i + 1, j, count, 1);
        if (dir == 2)
            dfs(grid, m, n, i - 1, j, count, 2);
        if (dir == 3)
            dfs(grid, m, n, i, j + 1, count, 3);
        if (dir == 4)
            dfs(grid, m, n, i, j - 1, count, 4);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int count = m * n;

        for (auto i : guards) {
            grid[i[0]][i[1]] = 1;
            count--;
        }

        for (auto i : walls) {
            grid[i[0]][i[1]] = 2;
            count--;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, m, n, i + 1, j, count, 1);
                    dfs(grid, m, n, i - 1, j, count, 2);
                    dfs(grid, m, n, i, j + 1, count, 3);
                    dfs(grid, m, n, i, j - 1, count, 4);
                }
            }
        }

        return count;
    }
};