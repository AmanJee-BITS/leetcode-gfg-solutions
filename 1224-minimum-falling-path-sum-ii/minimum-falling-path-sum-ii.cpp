class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int nextMin1 = 0, nextMin2 = 0;
        int nextMin1Pos = -1;

        for (int row = grid.size() - 1; row >= 0; --row) {
            int currMin1 = 1e9, currMin2 = 1e9;
            int currMin1Pos = -1;
            for (int col = grid[0].size() - 1; col >= 0; --col) {
                int ans;
                if (col != nextMin1Pos)
                    ans = grid[row][col] + nextMin1;
                else
                    ans = grid[row][col] + nextMin2;

                if (ans < currMin1) {
                    currMin2 = currMin1;
                    currMin1 = ans;
                    currMin1Pos = col;
                } else {
                    currMin2 = min(currMin2, ans);
                }
            }
            nextMin1 = currMin1;
            nextMin2 = currMin2;
            nextMin1Pos = currMin1Pos;
        }
        return nextMin1;
    }
};