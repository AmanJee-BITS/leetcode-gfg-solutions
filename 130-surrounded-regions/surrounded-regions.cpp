class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y, int row, int col) {
        if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O')
            return;

        board[x][y] = 'B';

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            dfs(board, x + dx[i], y + dy[i], row, col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, row, col);
            }
        }

        for (int j = 0; j < col; j++) {
            if (board[row - 1][j] == 'O') {
                dfs(board, row - 1, j, row, col);
            }
        }

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, row, col);
            }
        }

        for (int i = 0; i < row; i++) {
            if (board[i][col - 1] == 'O') {
                dfs(board, i, col - 1, row, col);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};