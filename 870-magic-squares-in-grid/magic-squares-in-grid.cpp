class Solution {
private:
    bool chkMatrix(vector<vector<int>>& grid) {
        vector<int> allNumber(10, 1);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] < 1 or grid[i][j] > 9)
                    return false;
                allNumber[grid[i][j]] -= 1;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (allNumber[i] != 0)
                return false;
        }

        return true;
    }

    bool helper(vector<vector<int>> sqGrid) {
        if (sqGrid.size() == 0)
            return false;

        if (!chkMatrix(sqGrid))
            return false;

        int chkrSum = INT_MAX;

        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += sqGrid[i][j];
            }
            if (chkrSum == INT_MAX)
                chkrSum = sum;
            else if (chkrSum != sum)
                return false;
        }
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += sqGrid[i][j];
            }
            if (chkrSum == INT_MAX)
                chkrSum = sum;
            else if (chkrSum != sum)
                return false;
        }

        int diag1 = sqGrid[0][0] + sqGrid[1][1] + sqGrid[2][2];
        int diag2 = sqGrid[2][0] + sqGrid[1][1] + sqGrid[0][2];

        return (diag1 == chkrSum) && (diag2 == chkrSum);
    }

    vector<vector<int>> generate(vector<vector<int>>& grid, int startR,
                                 int startC) {
        int row = grid.size();
        int col = grid[0].size();

        if (startR + 3 > row || startC + 3 > col)
            return {};

        vector<vector<int>> sqGrid;

        for (int i = startR; i < startR + 3; i++) {
            vector<int> currRow;
            for (int j = startC; j < startC + 3; j++) {
                currRow.push_back(grid[i][j]);
            }
            sqGrid.push_back(currRow);
        }
        
        return sqGrid;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans += helper(generate(grid, i, j));
            }
        }

        return ans;
    }
};